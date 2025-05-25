$exerciseFiles = Get-ChildItem -Path "exercises" -Filter *.cpp | Sort-Object Name
$progressFile = "progress.json"

if (!(Test-Path $progressFile)) {
    '{"completed": []}' | Out-File $progressFile -Encoding UTF8
}
$progress = Get-Content $progressFile | ConvertFrom-Json
$completed = $progress.completed

Write-Host "`nWelcome to C++ Practice: Design Patterns and OOP"

foreach ($exercise in $exerciseFiles) {
    $exerciseName = [System.IO.Path]::GetFileNameWithoutExtension($exercise.Name)
    $exercisePath = $exercise.FullName
    $readmePath = Join-Path "exercises" "$exerciseName.md"
    $solutionPath = Join-Path "solutions" "$exerciseName.cpp"

    if ($completed -contains $exercise.Name) {
        Write-Host "`nSkipping '$exerciseName' (already completed)"
        continue
    }

    Write-Host "`nExercise: $exerciseName"
    if (Test-Path $readmePath) {
        Write-Host "`nTask:"
        Get-Content $readmePath | ForEach-Object { Write-Host $_ }
    }

    Read-Host "`nPress [Enter] to compile and run your solution"

    g++ -Wall -Wextra -Werror $exercisePath -o temp.exe
    if ($LASTEXITCODE -eq 0) {
        ./temp.exe
        if ($LASTEXITCODE -eq 0) {
            Write-Host "`nSuccess! Marking as complete."

            $completed += $exercise.Name
            $progress.completed = $completed
            $progress | ConvertTo-Json | Out-File $progressFile -Encoding UTF8

            $showSolution = Read-Host "`nView the official solution? (y/n)"
            if ($showSolution -eq "y" -and (Test-Path $solutionPath)) {
                Write-Host "`nSolution:"
                Get-Content $solutionPath | ForEach-Object { Write-Host $_ }
            }
        } else {
            Write-Host "Runtime error. Please fix your code."
            break
        }
    } else {
        Write-Host "Compilation failed. Please fix your code."
        break
    }

    $done = $completed.Count
    $total = $exerciseFiles.Count
    $percent = [math]::Round(($done / $total) * 100)
    Write-Host "`nProgress: $done / $total ($percent`%)"
}

if ($completed.Count -eq $exerciseFiles.Count) {
    Write-Host "`nAll exercises completed! Great job!"
}
