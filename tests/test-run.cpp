// 1D average and average filter implementation
// Time: O(n)
// Space: O(n) corrresponding to input size
// by Maneesh Sutar

#include <iostream>
#include <chrono>

#include "../include/helpers.hpp"
#include "../include/filters.hpp"
#include "filterTests.hpp"

//g++ -std=c++11 -o outputFilter main.cpp

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "performing tests ..." << endl;

    shouldReturnAverageFilteredValuesWhenInputIsProvided();
    shouldReturnMedianFilteredValuesWhenInputIsProvided();
    // shouldThrowErrorWhenFilterSizeIsGreaterThanInputSize();
    // shouldThrowErrorWhenFilterSizeIsLessThanOrEqualToZero();

    shouldReturnPaddedAverageFilteredValuesWhenInputIsProvided();
    shouldReturnPaddedMedianFilteredValuesWhenInputIsProvided();
    
    cout << endl << "all tests passed ..." << endl;
    return 0;
}


