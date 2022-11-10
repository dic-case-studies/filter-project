// 1D average and average filter implementation
// Time: O(n)
// Space: O(n) corrresponding to input size
// by Maneesh Sutar

#include <iostream>
#include <chrono>

#include "./include/helpers.hpp"
#include "./include/filters.hpp"

using namespace std;

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

    float input[inputSize];
    int lowerLimit = 10;
    int upperLimit = 100;
    srand((unsigned)time(0));
    for (int i = 0; i < inputSize; i++)
    {
        input[i] = generateRandomNumberInRange(lowerLimit, upperLimit);
    }

    vector<float> output;

    auto start = chrono::high_resolution_clock::now();
    output = filter(inputSize, filterSize, input, &averageFilter);
    auto stop = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "The time taken for average filter is: " << duration.count() << endl;

    start = chrono::high_resolution_clock::now();
    output = filter(inputSize, filterSize, input, &medianFilter);
    stop = chrono::high_resolution_clock::now();

    duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "The time taken for median filter is: " << duration.count() << endl;

    cout << endl;

    return 0;
}
