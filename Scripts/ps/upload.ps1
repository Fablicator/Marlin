try {
    Stop-Process -Name "fablicator" -ErrorAction "SilentlyContinue"
}catch{}
Set-Location "$PSScriptRoot\..\..\"
platformio run --target upload