# Project Helper
![Demo](https://github.com/shhossain/projectHelper/blob/main/example_projectHelper.gif)

## Features
- Quickly navigate to project directories

## To-do
- [ ] Project creation feature

## Setup for Windows
1. Set the `CODE_PATH` environment variable to the path where your projects are located.
2. Download the [projectHelper.exe](https://github.com/shhossain/projectHelper/releases/download/v0.0.1/projectHelper.exe) file.
3. Add the executable to your system's PATH.
4. Paste the following code into your PowerShell profile (you can open it by running `notepad $PROFILE` in PowerShell):

```powershell
function p {
    $path = Invoke-Expression "projectHelper.exe $args"
    cd $path
}
```