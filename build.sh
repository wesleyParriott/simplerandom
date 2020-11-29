projectName=$(pwd | awk '{n=split($0,a,"/"); print a[n]}')
if [ ! -d "bin" ]; then
    mkdir bin
fi
gcc -g -o bin/$projectName $projectName.c 2>&1
if [ $? -eq 0 ]; then
    if [ "$1" == "run" ]; then
        ./bin/$projectName
    fi
fi
