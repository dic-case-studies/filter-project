#!/usr/bin/env bash

echo "Running make"
(make clean > /dev/null) && (make FLAG="-D TWOD" > /dev/null)

outputFile=timeBenchmarks.txt

if [ -f $outputFile ]
then
    rm $outputFile
fi

iterations=$1
inputSize=$2
filterSize=$3

echo "Sequence of the filters: twoDAverageFilter twoDMedianFilter" >> $outputFile
echo >> $outputFile

echo "Running app for ${iterations} iterations, recording output in $outputFile"

for((i=1; i<=iterations; i++)){
    echo "iteration $i" >> $outputFile
    ./benchmark-app ${inputSize} ${filterSize} >> $outputFile
    echo >> $outputFile
}

echo "Done"
echo "--------------------------------------------" >> $outputFile
echo "Sequence of the filters: averageFilter, medianFilter, medianFilterWithStdNthElementFunction " >> $outputFile
(make clean > /dev/null) && (make > /dev/null)

echo >> $outputFile

echo "Running app for ${iterations} iterations, recording output in $outputFile"

for((i=1; i<=iterations; i++)){
    echo "iteration $i" >> $outputFile
    ./benchmark-app ${inputSize} ${filterSize} >> $outputFile
    echo >> $outputFile
}

echo "Done"
