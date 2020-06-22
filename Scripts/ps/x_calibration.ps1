Write-Host "Fablicator X Axis Calibration"
Write-Host ""
Write-Host "Warning! " -NoNewline -ForegroundColor Red
Write-Host "This calibration should only be done if:"
Write-Host ""
Write-Host "    - You replaced the X axis"
Write-Host "    - The original calibration file is lost"
Write-Host ""
Write-Host "    Also, be sure the Z axis is calibrated before running this."
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
# Pause

## Find the port the printer is on
$found_port = $false
ForEach ($portname in ([System.IO.Ports.SerialPort]::getportnames())) { 
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
$port.WriteLine("G0 Z0.5 Y1")

Write-Host "#### X Axis Calibration ####" -ForegroundColor Red
Write-Host ""
Write-Host "Moving to starting position for X axis calibration"
Start-Sleep 1
Write-Host ""
Write-Host "(Only press enter when it's finished moving)"
Start-Sleep 1
Write-Host ""
Pause
Clear-Host

# Run X1 Calibration

$x1_offset = 0
do{
    Clear-Host
    Write-Host "#### Left Extruder Calibration ####" -ForegroundColor Red
    Write-Host ""
    Write-Host "Move the left extruder left and right until the tip of the nozzle"
    Write-Host "is on the left edge of the bed glass"
    Write-Host ""
    Write-Host "CONTROLS:"
    Write-Host ""
    Write-Host "    'q' - left 0.1mm"
    Write-Host "    'e' - right 0.1mm"
    Write-Host "    'a' - left 1mm"
    Write-Host "    'd' - right 1mm"
    Write-Host ""
    Write-Host "Press 'c' to finish"
    Write-Host ""
    Write-Host "X1 Offset = $x1_offset"
    $key = (Get-Host).UI.RawUI.ReadKey().Character;

    $port.WriteLine("G91")
    $port.WriteLine("T0")

    if($key -eq 'q') {
        $x1_offset -= 0.1
        $port.WriteLine("G0 X-0.1")
    }elseif($key -eq 'e') {
        $x1_offset += 0.1
        $port.WriteLine("G0 X0.1")
    }elseif($key -eq 'a') {
        $x1_offset -= 1
        $port.WriteLine("G0 X-1")
    }elseif($key -eq 'd') {
        $x1_offset += 1
        $port.WriteLine("G0 X1")
    }elseif($key -eq 'c') {
        break
    }

    if($x1_offset -lt 0) {$x1_offset = 0}
    $x1_offset = [math]::Round($x1_offset,1)
    Start-Sleep 0.5
}while($true)

Clear-Host
Write-Host "Left Extruder Calibration Complete" -ForegroundColor Green
Start-Sleep -Seconds 1.5

# Run X2 calibration if we are using an MX

if($machine_type -match "mx") {
    $x2_offset = 0
    do{
        Clear-Host
        Write-Host "#### Right extruder Calibration ####" -ForegroundColor Red
        Write-Host ""
        Write-Host "Move the right extruder left and right until the tip of the nozzle"
        Write-Host "is on the right edge of the bed glass"
        Write-Host ""
        Write-Host "CONTROLS:"
        Write-Host ""
        Write-Host "    'q' - left 0.1mm"
        Write-Host "    'e' - right 0.1mm"
        Write-Host "    'a' - left 1mm"
        Write-Host "    'd' - right 1mm"
        Write-Host ""
        Write-Host "Press 'c' to finish"
        Write-Host ""
        Write-Host "X1 Offset = $x2_offset"
        $key = (Get-Host).UI.RawUI.ReadKey().Character;

        $port.WriteLine("G91")
        $port.WriteLine("T1")

        if($key -eq 'q') {
            $x2_offset += 0.1
            $port.WriteLine("G0 X-0.1")
        }elseif($key -eq 'e') {
            $x2_offset -= 0.1
            $port.WriteLine("G0 X0.1")
        }elseif($key -eq 'a') {
            $x2_offset += 1
            $port.WriteLine("G0 X-1")
        }elseif($key -eq 'd') {
            $x2_offset -= 1
            $port.WriteLine("G0 X1")
        }elseif($key -eq 'c') {
            break
        }

        if($x2_offset -lt 0) {$x2_offset = 0}
        $x2_offset = [math]::Round($x2_offset,1)
        Start-Sleep 0.5
    }while($true)
    
    Clear-Host
    Write-Host "Right Extruder Calibration Complete" -ForegroundColor Green
    Start-Sleep -Seconds 1.5
}


Clear-Host 
Write-Host "Calibration complete.." -ForegroundColor Green
Start-Sleep -Seconds 1
Write-Host ""
Write-Host "Previewing changes to Calibration.h"
Write-Host ""
Start-Sleep -Seconds 1
Write-Host "Each change is denoted by a red arrow ("-NoNewline
Write-Host "-->>" -NoNewline -ForegroundColor Red
Write-Host ")"
Write-Host ""
Start-Sleep -Seconds 2

Clear-Host

$temp_file = "$PSScriptRoot\cal_temp"
if(Test-Path $temp_file) {
    Remove-Item $temp_file
}

New-Item $temp_file > $null

foreach ($line in Get-Content $calibration_h) {
    ## Diff X1_BED_OFFSET
    $target_def = "X1_BED_OFFSET"
    if(Is-Defined $line $target_def){
        Write-Host $line -NoNewline
        Write-Host "    -->>    " -NoNewline -ForegroundColor Red
        $diff = (Replace-DefineNumber $line $target_def ([string]$x1_offset))
        Write-Host $diff -ForegroundColor Green
        Add-Content $temp_file $diff
        continue
    }

    if($machine_type -match "mx") {
        ## Diff X2_BED_OFFSET
        $target_def = "X2_BED_OFFSET"
        if(Is-Defined $line $target_def){
            Write-Host $line -NoNewline
            Write-Host "    -->>    " -NoNewline -ForegroundColor Red
            $diff = (Replace-DefineNumber $line $target_def ([string]$x2_offset))
            Write-Host $diff -ForegroundColor Green
            Add-Content $temp_file $diff
            continue
        }
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