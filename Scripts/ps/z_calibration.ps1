Write-Host "Fablicator Z Axis Calibration"
Write-Host ""
Write-Host "Warning! " -NoNewline -ForegroundColor Red
Write-Host "This calibration should only be done if:"
Write-Host ""
Write-Host "    - The bed is replaced"
Write-Host "    - The original calibration file is lost"
Write-Host ""
Write-Host "Before calibrating the machine, we're going to upload the firmware."
Write-Host ""
Write-Host "This will ensure that we are doing a proper calibration."
Write-Host ""
Write-Host ""
Pause

Clear-Host
Write-Host "Uploading firmware..."
Start-Sleep 1
Set-Location $PSScriptRoot
Start-Process powershell "-ExecutionPolicy Bypass -File .\upload.ps1" -NoNewWindow -Wait

# Check is the item is defined
function Is-Defined($line, $def) {
    if(($line -match "\s*#define\s+$def.*") -and !($line -match "^\s*\/\/.*")){
        return $true
    }

    return $false
}

# Get the value of the define if it's a number
# Otherwise, returns an empty string
# This must be parsed into a number because the return is always a string
function Get-DefineNumber($line, $def) {
    if($line -match "\s*#define\s+$def\s+(\d+\.?\d*)\s*") {
        return $Matches.1
    }
    return ""
}

# Replace number definition for a define
function Replace-DefineNumber($line, $def, $new_value) {
    if(Is-Defined $line $def) {
        return "#define $def $new_value"
    }
    
    return ""
}

$bed_center_x = 0
$bed_center_y = 0
Clear-Host
Write-Host "Checking Calibration.h for the machine type"
Start-Sleep 1
Write-Host ""
$machine_type = ""
$calibration_h = "$PSScriptRoot\..\..\Marlin\Calibration.h"
foreach ($line in Get-Content $calibration_h) {
    if(Is-Defined $line "USING_MX") {
        Write-Host "You are using an MX" -ForegroundColor Green
        $machine_type = "mx"
        $bed_center_x = 175
        $bed_center_y = 108
        break
    }elseif(Is-Defined $line "USING_SX") {
        Write-Host "You are using an SX" -ForegroundColor Green
        $machine_type = "sx"
        $bed_center_x = 108
        $bed_center_y = 108
        break
    }elseif(Is-Defined $line "USING_FM1") {
        Write-Host "You are using an FM1" -ForegroundColor Green
        $machine_type = "fm1"
        $bed_center_x = 88
        $bed_center_y = 88
        break
    }
}

if(!($machine_type)) {
    Write-Host "Unknown machine type. Please check your Calibration.h or load defaults."
    Write-Host ""
    Pause
    exit
}
Write-Host ""

## Find the port the printer is on
$found_port = $false
ForEach ($portname in ([System.IO.Ports.SerialPort]::getportnames())) {
    try{
        $port = new-object System.IO.Ports.SerialPort $portname,250000,None,8,one
        $port.Open()
        $port.DtrEnable = $true
        $port.DtrEnable = $false
        Start-Sleep -Seconds 0.5
        $port.ReadLine() > $null; # Toss first line
        if(($port.ReadLine()) -match "Marlin") {
            $found_port = $true
            $port.Close()
            # Write-Host "Printer found at: $portname" -ForegroundColor Green
            # Start-Sleep -Seconds 1
            break
        }
        $port.Close()
        $port.Dispose()
    }catch {}
}

if(!($found_port)) {
    Clear-Host
    Write-Host "Can't find printer port!" -ForegroundColor Red
    Write-Host ""
    Start-Sleep -Seconds 1
    Pause
    exit
}

Clear-Host

## Start calibration

# Run Z Calibration
$port.Open()
$port.WriteLine("G28")
$port.WriteLine("G0 Z10 X$bed_center_x Y$bed_center_y")
$port.WriteLine("G92 Z0")

Write-Host "#### Z-Calibration ####" -ForegroundColor Red
Write-Host ""

$z_offset = 10

Write-Host "Homing printer and moving nozzle above bed..."
Start-Sleep 1
Write-Host ""
Write-Host "(Only press enter when it's finished moving)"
Start-Sleep 1
Write-Host ""
Pause

Clear-Host
Write-Host "#### Z-Calibration ####" -ForegroundColor Red
Write-Host ""
Write-Host "Take a piece of paper and slide it between the nozzle and bed"
Write-Host ""
Start-Sleep -Seconds 1
Pause
do{
    Clear-Host
    Write-Host "#### Z-Calibration ####" -ForegroundColor Red
    Write-Host ""
    Write-Host "Slide the paper back and forth under the the nozzle"
    Write-Host ""
    Write-Host "While doing this, lower the nozzle until you can't move the paper."
    Write-Host ""
    Write-Host "CONTROLS:"
    Write-Host ""
    Write-Host "    'w' - up 0.1mm"
    Write-Host "    's' - down 0.1mm"
    Write-Host "    'r' - up 1mm"
    Write-Host "    'f' - down 1mm"
    Write-Host ""
    Write-Host "Press 'c' to finish"
    Write-Host ""
    Write-Host "Bed Height Offset = $z_offset"
    if($z_offset -lt 1.5) {
        Write-Host ""
        Write-Host "Be careful going lower!" -ForegroundColor Red
    }
    $key = (Get-Host).UI.RawUI.ReadKey().Character;
    
    if($key -eq 'w') {
        $z_offset += 0.1
        $port.WriteLine("G92 Z0")
        $port.WriteLine("G0 Z0.1")
    }elseif($key -eq 's') {
        $z_offset -= 0.1
        $port.WriteLine("G92 Z0.1")
        $port.WriteLine("G0 Z0")
    }elseif($key -eq 'r') {
        $z_offset += 1
        $port.WriteLine("G92 Z0")
        $port.WriteLine("G0 Z1")
    }elseif($key -eq 'f') {
        $z_offset -= 1
        $port.WriteLine("G92 Z1")
        $port.WriteLine("G0 Z0")
    }elseif($key -eq 'c') {
        $z_offset = [math]::Round($z_offset,1)
        break
    }
    $z_offset = [math]::Round($z_offset,1)
    Start-Sleep 0.25
}while($true)

$port.WriteLine("G92 Z0")
$port.WriteLine("G0 Z10")

Clear-Host
Write-Host "Z Calibration Complete" -ForegroundColor Green
Start-Sleep -Seconds 1.5
Clear-Host
$port.Close()

Write-Host "PREVIEW OF " -NoNewline
Write-Host "Calibration.h" -ForegroundColor Green
Write-Host ""
Write-Host "Changes are denoted by red arrow ( " -NoNewline
Write-Host "-->>" -NoNewline -ForegroundColor Red
Write-Host " )"
Write-Host ""
Write-Host ""
Write-Host "------------------------------------------------"
Write-Host ""
Write-Host ""

$temp_file = "$PSScriptRoot\cal_temp"
if(Test-Path $temp_file) {
    Remove-Item $temp_file
}

New-Item $temp_file > $null

foreach ($line in Get-Content $calibration_h) {
    ## Diff Z_MAX_POS
    $target_def = "Z_MAX_POS"
    $def_val = [double](Get-DefineNumber $line $target_def)
    $def_val += $z_offset
    if(Is-Defined $line $target_def){
        Write-Host $line -NoNewline
        Write-Host "    -->>    " -NoNewline -ForegroundColor Red
        $diff = (Replace-DefineNumber $line $target_def ([string]$def_val))
        Write-Host $diff -ForegroundColor Green
        Add-Content $temp_file $diff
        continue
    }

    Write-Host $line
    Add-Content $temp_file $line
}

Write-Host ""
Write-Host ""
Pause

Clear-Host

Write-Host "Accept changes? These will be uploaded to the board."
Write-Host "y - yes"
Write-Host "n - no"
Write-Host ""

$write_changes = $false
do {
    $resp = Read-Host "Enter y or n"
    if($resp -match "y") {
        $write_changes = $true
        break
    }elseif ($resp -match "n") {
        break
    }
}while($true)

if($write_changes) {
    Remove-Item $calibration_h
    Copy-Item $temp_file $calibration_h
    Set-Location $PSScriptRoot
    Start-Process powershell "-ExecutionPolicy Bypass -File .\upload.ps1" -NoNewWindow -Wait
}

Remove-Item $temp_file