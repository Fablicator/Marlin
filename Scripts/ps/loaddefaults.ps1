Clear-Host
Write-Host "What kind of machine do you have?"
Write-Host ""
Write-Host "    'mx'    - Fablicator MX"
Write-Host "    'sx'    - Fablicator SX"
Write-Host "    'fm1'   - Fablicator FM-1"
Write-Host ""
do{ 
    $machine_type = Read-Host "Enter choice"
    if($machine_type -match "mx") {
        $default_file = "$PSScriptRoot\..\..\CalibrationDefaults\MX\Calibration.h"
        break
    }elseif($machine_type -match "sx") {
        $default_file = "$PSScriptRoot\..\..\CalibrationDefaults\SX\Calibration.h"
        break
    }elseif($machine_type -match "fm1") {
        $default_file = "$PSScriptRoot\..\..\CalibrationDefaults\FM1\Calibration.h"
        break
    }
}while($true)

if(Test-Path "$PSScriptRoot\..\..\Marlin\Calibration.h") {
    Clear-Host
    Write-Host "Calibration.h already exists would you like to overwrite it?"
    Write-Host ""
    Write-Host "'y' - Overwrite" -ForegroundColor Green
    Write-Host "'n' - Don't overwrite" -ForegroundColor Red
    Write-Host ""
    do{
        $resp = Read-Host "-"
        if($resp -match 'y') {
            Remove-Item "$PSScriptRoot\..\..\Marlin\Calibration.h"
            break
        }elseif($resp -match 'n') {
            exit
        }
    }while($true)

}

Copy-Item $default_file "$PSScriptRoot\..\..\Marlin\"
Clear-Host
Write-Host "Defaults loaded"
Start-Sleep -Seconds 1
Clear-Host
Write-Host "!!!! WARNING !!!!" -ForegroundColor Red
Write-Host ""
Write-Host "This machine needs to be calibrated before using it" -ForegroundColor Red
Write-Host ""
Write-Host "!!!! WARNING !!!!" -ForegroundColor Red
Write-Host ""
Pause