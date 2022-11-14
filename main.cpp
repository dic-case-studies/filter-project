// 1D average and average filter implementation
// Time: O(n)
// Space: O(n) corrresponding to input size
// by Maneesh Sutar

#include <iostream>
#include <fstream>
#include <chrono>
#include <string.h>
#include <vector>
#include <math.h>
#include <iterator>
#include <random>

#include "./include/helpers.hpp"
#include "./include/filters.hpp"

using std::cout;
using std::endl;
using std::vector;

int main(int argc, char const *argv[])
{
    int inputSize, filterSize;

    // run for different values
    // if (argc != 3)
    //     throw std::invalid_argument("provide both inputs");

    // inputSize = std::atoi(argv[1]);
    // filterSize = std::atoi(argv[2]);

    inputSize = 1000;
    filterSize = 9;

    std::vector<float> input(inputSize);
    // int lowerLimit = -1;
    // int upperLimit = 1;
    srand((unsigned)time(0));

    // to generate noise
    const float mean = 0.0;
    const float stddev = 0.2;
    std::default_random_engine generator;
    std::normal_distribution<float> dist(mean, stddev);

    double amplitude = 5;
    float frequency = 1; // Hz
    float shift = 0;

    for (int i = 0; i < inputSize; i++)
    {
        input[i] = amplitude * sin(2 * M_PI * (frequency / inputSize) * i + shift) + dist(generator);
    }

#ifdef GRAPHS
    // writing input to a file
    std::ofstream InputFile("./out/input.txt");

    for (int i = 0; i < inputSize; i++)
    {
        InputFile << i << " " << input[i] << endl;
    }
    InputFile.close();
#endif

    std::vector<float> output;

#ifndef GRAPHS
    vector<float> (*filters[])(vector<float>, int, int) = {averageFilter, medianFilter, medianFilterWithStdNthElementFunction};
    int nFilter = 3;

    for (int i = 0; i < nFilter; i++)
    {
#endif
        auto start = std::chrono::high_resolution_clock::now();
#ifndef GRAPHS
        output = filter(input, inputSize, filterSize, filters[i]);
#endif

#ifdef GRAPHS  
        output = filter(input, inputSize, filterSize, medianFilter);      
#endif
        auto stop = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

        std::cout << duration.count() << " us" << std::endl;

#ifndef GRAPHS    
    }
#endif

#ifdef GRAPHS
    // writing to a output
    std::ofstream OutputFile("./out/output.txt");
    for (int i = 0; i < inputSize; i++)
    {
        OutputFile << i << " " << output[i] << endl;
    }
    OutputFile.close();
#endif

    return 0;
}
