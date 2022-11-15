#include "filterTests.hpp"

#include <chrono>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::cout << "performing tests ..." << std::endl;

    shouldReturnAverageFilteredValuesWhenInputIsProvided();
    shouldReturnMedianFilteredValuesWhenInputIsProvided();

    // shouldThrowErrorWhenFilterSizeIsGreaterThanInputSize();
    // shouldThrowErrorWhenFilterSizeIsLessThanOrEqualToZero();

    shouldReturnPaddedAverageFilteredValuesWhenInputIsProvided();
    shouldReturnPaddedMedianFilteredValuesWhenInputIsProvided();

    shouldReturnMedianFilteredValuesWithStdNthElementFunctionWhenInputIsProvided();
    
    std::cout << std::endl << "all tests passed ..." << std::endl;
    return 0;
}


