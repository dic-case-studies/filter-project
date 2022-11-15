#!/usr/bin/env bash

if [ -d ./out ]
then
    rm -rf out
fi 

mkdir ./out

echo "Running make"
(make clean > /dev/null) && (make benchmark-app > /dev/null)

echo "Running app and recording time"
./main-app > ./out/time.txt

echo "Creating graphs"
graph -T png ./out/input.txt > ./out/input.png  
graph -T png ./out/output.txt > ./out/output.png