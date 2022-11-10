
#include "../include/filters.hpp"
#include <assert.h>
#include <vector>
using namespace std;

void shouldReturnAverageFilteredValuesWhenInputIsProvided()
{
    int inputSize, filterSize;

    inputSize = 10;
    filterSize = 5;

    float input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    float expectedOutput[] = {3, 4, 5, 6, 7, 8};

    vector<float> output;
    output = filter(inputSize, filterSize, input, averageFilter);

    for (int i = 0; i < sizeof(expectedOutput) / sizeof(expectedOutput[0]); i++)
    {
        assert(output[i] == expectedOutput[i]);
    }

}

void shouldReturnMedianFilteredValuesWhenInputIsProvided()
{
    int inputSize, filterSize;

    inputSize = 10;
    filterSize = 5;

    float input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    float expectedOutput[] = {3, 4, 5, 6, 7, 8};

    vector<float> output;
    output = filter(inputSize, filterSize, input, medianFilter);

    for (int i = 0; i < sizeof(expectedOutput) / sizeof(expectedOutput[0]); i++)
    {
        assert(output[i] == expectedOutput[i]);
    }

}

void shouldThrowErrorWhenFilterSizeIsGreaterThanInputSize()
{
    int inputSize, filterSize;

    inputSize = 9;
    filterSize = 20;

    float input[] = {2, 4, 6, 8, 1, 3, 5, 7, 9};

    bool invalidArgumentExceptionThrown = false;
    try
    {
        filter(inputSize, filterSize, input, averageFilter);
    }
    catch (std::invalid_argument &e)
    {
        invalidArgumentExceptionThrown = true;
    }

    assert(invalidArgumentExceptionThrown);
}

void shouldThrowErrorWhenFilterSizeIsLessThanOrEqualToZero()
{
    int inputSize, filterSize;

    inputSize = 9;
    filterSize = 0;

    float input[] = {2, 4, 6, 8, 1, 3, 5, 7, 9};

    bool invalidArgumentExceptionThrown = false;
    try
    {
        filter(inputSize, filterSize, input, averageFilter);
    }
    catch (std::invalid_argument &e)
    {
        invalidArgumentExceptionThrown = true;
    }

    assert(invalidArgumentExceptionThrown);
}


void shouldReturnPaddedAverageFilteredValuesWhenInputIsProvided()
{
    int inputSize, filterSize;

    inputSize = 10;
    filterSize = 5;

    float input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    float expectedOutput[] = {1.2, 2, 3, 4, 5, 6, 7, 8, 6.8 , 5.4 };

    vector<float> output;
    output = filter(inputSize, filterSize, input, paddedAverageFilter);

    for (int i = 0; i < sizeof(expectedOutput) / sizeof(expectedOutput[0]); i++)
    {
        assert(output[i] == expectedOutput[i]);
    }

}

void shouldReturnPaddedMedianFilteredValuesWhenInputIsProvided(){
    int inputSize, filterSize;

    inputSize = 10;
    filterSize = 5;

    float input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    float expectedOutput[] = {1, 2, 3, 4, 5, 6, 7, 8 , 8, 8};

    vector<float> output;
    output = filter(inputSize, filterSize, input, paddedMedianFilter);

    for (int i = 0; i < sizeof(expectedOutput) / sizeof(expectedOutput[0]); i++)
    {
        assert(output[i] == expectedOutput[i]);
    }

}

