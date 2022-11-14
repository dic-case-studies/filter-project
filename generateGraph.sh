#!/usr/bin/env bash

mkdir -p ./out

echo "Running make"
make > /dev/null

echo "Running app and recording time"
./app > ./out/time.txt

echo "Creating graphs"
graph -T png ./out/input.txt > ./out/input.png  
graph -T png ./out/output.txt > ./out/output.png