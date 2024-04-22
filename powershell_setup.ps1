function p{
    $path = Invoke-Expression "projectHelper.exe $args"
    cd $path
}