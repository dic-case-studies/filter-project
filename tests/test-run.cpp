// 1D average and average filter implementation
// Time: O(n)
// Space: O(n) corrresponding to input size
// by Maneesh Sutar

#include <iostream>
#include <chrono>

#include "../include/helpers.hpp"
#include "../include/filters.hpp"
#include "filterTests.hpp"

int main(int argc, char const *argv[])
{
    std::cout << "performing tests ..." << std::endl;

    shouldReturnAverageFilteredValuesWhenInputIsProvided();
    shouldReturnMedianFilteredValuesWhenInputIsProvided();
    // shouldThrowErrorWhenFilterSizeIsGreaterThanInputSize();
    // shouldThrowErrorWhenFilterSizeIsLessThanOrEqualToZero();

    shouldReturnPaddedAverageFilteredValuesWhenInputIsProvided();
    shouldReturnPaddedMedianFilteredValuesWhenInputIsProvided();
    
    std::cout << std::endl << "all tests passed ..." << std::endl;
    return 0;
}


