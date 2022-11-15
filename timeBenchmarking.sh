#!/usr/bin/env bash

echo "Running make"
(make clean > /dev/null) && (make main-app > /dev/null)

outputFile=timeBenchmarks.txt

if [ -f $outputFile ]
then
    rm $outputFile
fi

iterations=$1

echo "Sequence of the filters: averageFilter, medianFilter, medianFilterWithStdNthElementFunction" >> $outputFile
echo >> $outputFile

echo "Running app for ${iterations} iterations, recording output in $outputFile"

for((i=1; i<=iterations; i++)){
    echo "iteration $i" >> $outputFile
    ./benchmark-app >> $outputFile
    echo >> $outputFile
}

echo "Done"
