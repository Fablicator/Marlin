$branch = (git rev-parse --abbrev-ref HEAD)

git fetch

$commitcount = (git log $branch..origin/$branch --oneline | Measure-Object).Count

if($commitcount -eq 0) {
    Clear-Host
    Write-Host "No update available..."
    pause
    exit
}else{
    Clear-Host
    Write-Host "The following updates are available:"
    git log $branch..origin/$branch --oneline
    do {
        $shouldupdate = Read-Host -Prompt "Would you like to update? (Enter 'y' to update or 'n' to cancel) "
        if($shouldupdate -match 'y') {
            break
        }elseif($shouldupdate -match 'n') {
            exit
        }
    }while($true)
}

Clear-Host
Write-Host "Updating software..."
git pull origin $branch
git reset --hard origin/$branch

Clear-Host
Write-Host "Update complete!"
pause