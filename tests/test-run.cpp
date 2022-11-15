#include "filterTests.hpp"

#include <chrono>
#include <gtest/gtest.h>
#include <iostream>

int main(int argc, char *argv[])
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

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}


