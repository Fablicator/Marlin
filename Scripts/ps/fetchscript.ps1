$branch = "fablicator-fw-2.0-stable"
# $docsdir = [Environment]::GetFolderPath('MyDocuments')

Clear-Host

"Fetching updates in the background..."
powershell -window minimized -command "" > $null

git fetch

$commitcount = (git log $branch..origin/$branch --oneline | Measure-Object).Count

if($commitcount -eq 0) {
    Clear-Host
    "No update available..."
    powershell -window normal -command "" > $null
    pause
    exit
}else{
    Clear-Host
    
    powershell -window normal -command "" > $null

    "The following updates are available:"
    git log $branch..origin/$branch --oneline

    $shouldupdate = Read-Host -Prompt "Would you like to update? (Enter 'Y' to update or 'N' to cancel) "
    
    if($shouldupdate -ne "Y") {
        exit
    }
}

Clear-Host
"Updating software..."
git pull origin $branch
git reset --hard origin/$branch

Clear-Host
"Update complete!"
pause