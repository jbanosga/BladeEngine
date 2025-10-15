#!/bin/bash

compile_func()
{
    mkdir -p build
    cd build
    cmake ..
    cmake --build .
    cd ..
}

run_func()
{
    ./build/BladeEngine &
}

display_options()
{
    echo "###########################"
    echo "###########################"
    echo "  " 
    echo "BLADE ENGINE ACTION MANAGER"
    echo "Select Option:"
    echo "  -   [1] Compile"
    echo "  -   [2] Run"
    echo "  -   [3] Compile + Run"
    echo "  -   [4] Quit"
    echo "  " 
    echo "###########################"
    echo "###########################"
}

while [[ true ]]; do
    display_options 
    read key_pressed
    case $key_pressed in
        1) 
            compile_func
            ;;
        2)
            run_func
            ;;
        3)
            compile_func
            run_func
            ;;
        4)
            exit
            ;;
    esac
done