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
    int inputSize, filterSize;

    // run for different values
    //    if(argc != 3)
    //        throw std::invalid_argument("provide both inputs");
    //
    //    inputSize = std::atoi(argv[1]);
    //    filterSize = std::atoi(argv[2]);

    inputSize = 10000;
    filterSize = 5;

    std::vector<float> input(inputSize);
    int lowerLimit = 10;
    int upperLimit = 100;
    srand((unsigned)time(0));
    for (int i = 0; i < inputSize; i++)
    {
        input.push_back(generateRandomNumberInRange(lowerLimit, upperLimit));
    }

    std::vector<float> output;

    int n = 3;

    for (int i = 0; i < n; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        auto output = filter(input, inputSize, filterSize, medianFilterWithStdNthElementFunction);
        auto stop = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

        std::cout << "The time taken for filter is: " << duration.count() << std::endl;
    }

    return 0;
}
