
#include "../include/filters.hpp"
#include <assert.h>
#include <vector>
using namespace std;
using std::vector;

void shouldReturnAverageFilteredValuesWhenInputIsProvided()
{
    int inputSize, filterSize;

    inputSize = 10;
    filterSize = 5;

    float expectedOutput[] = {3, 4, 5, 6, 7, 8};

    vector<float> input{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    vector<float> output;
    output = filter(input, inputSize, filterSize, averageFilter);

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

    float expectedOutput[] = {3, 4, 5, 6, 7, 8};

    vector<float> input{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    vector<float> output;
    output = filter(input, inputSize, filterSize, medianFilter);

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

    vector<float> input{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    bool invalidArgumentExceptionThrown = false;
    try
    {
        filter(input, inputSize, filterSize, averageFilter);
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

    vector<float> input{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    bool invalidArgumentExceptionThrown = false;
    try
    {
        filter(input, inputSize, filterSize, averageFilter);
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

    vector<float> input{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    float expectedOutput[] = {1.2, 2, 3, 4, 5, 6, 7, 8, 6.8 , 5.4 };

    vector<float> output;
    output = filter(input, inputSize, filterSize, paddedAverageFilter);

    for (int i = 0; i < sizeof(expectedOutput) / sizeof(expectedOutput[0]); i++)
    {
        assert(output[i] == expectedOutput[i]);
    }

}

void shouldReturnPaddedMedianFilteredValuesWhenInputIsProvided(){
    int inputSize, filterSize;

    inputSize = 10;
    filterSize = 5;

    vector<float> input{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    float expectedOutput[] = {1, 2, 3, 4, 5, 6, 7, 8 , 8, 8};

    vector<float> output;
    output = filter(input, inputSize, filterSize, paddedMedianFilter);

    for (int i = 0; i < sizeof(expectedOutput) / sizeof(expectedOutput[0]); i++)
    {
        assert(output[i] == expectedOutput[i]);
    }

}

