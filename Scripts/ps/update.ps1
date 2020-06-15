$branch = (git rev-parse --abbrev-ref HEAD)

git fetch

$commitcount = (git log $branch..origin/$branch --oneline | Measure-Object).Count

if($commitcount -eq 0) {
    Clear-Host
    "No update available..."
    pause
    exit
}else{
    Clear-Host
    "The following updates are available:"
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
"Updating software..."
git pull origin $branch
git reset --hard origin/$branch

Clear-Host
"Update complete!"
pause