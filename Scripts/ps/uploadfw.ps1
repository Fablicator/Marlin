$shouldupload = Read-Host -Prompt "Would you like to upload the new firmware to your printer? ( 'Y' to upload or press enter to cancel)"
if($shouldupload -ne "Y") {exit}

"Attempting to upload using PlatformIO"

if(!(Get-Command python -ErrorAction SilentlyContinue)) {
    "Python is not installed on this system please install it from http://www.python.org then rerun the script."
    exit
}

if(!(Get-Command pio -ErrorAction SilentlyContinue)) {
    "Installing PlatformIO"
    pip install platformio
}

pio run -t upload