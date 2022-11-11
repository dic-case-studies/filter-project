// 1D average and average filter implementation
// Time: O(n)
// Space: O(n) corrresponding to input size
// by Maneesh Sutar

#include <iostream>
#include <chrono>

#include "./include/helpers.hpp"
#include "./include/filters.hpp"

int main(int argc, char const *argv[])
{
    int inputSize, filterSize, outputSize;

    // run for different values
    //    if(argc != 3)
    //        throw std::invalid_argument("provide both inputs");
    //
    //    inputSize = std::atoi(argv[1]);
    //    filterSize = std::atoi(argv[2]);

    inputSize = 10000;
    filterSize = 10;

    outputSize = inputSize - filterSize + 1;

    std::vector<float> input(inputSize);
    int lowerLimit = 10;
    int upperLimit = 100;
    srand((unsigned)time(0));
    for (int i = 0; i < inputSize; i++)
    {
        input.push_back(generateRandomNumberInRange(lowerLimit, upperLimit));
    }

    std::vector<float> output;

    auto start = std::chrono::high_resolution_clock::now();
    output = filter(input, inputSize, filterSize, &averageFilter);
    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "The time taken for average filter is: " << duration.count() << std::endl;

    start = std::chrono::high_resolution_clock::now();
    output = filter(input, inputSize, filterSize, &medianFilter);
    stop = std::chrono::high_resolution_clock::now();

    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "The time taken for median filter is: " << duration.count() << std::endl;

    std::cout << std::endl;

    return 0;
}
