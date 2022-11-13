// 1D median filter implementation
// Time: O(n)
// Space: O(n) corrresponding to input size
// by Maneesh Sutar

#include <vector>
#include <algorithm>
#include <assert.h>
// #include <iostream>

#include "../include/helpers.hpp"

using std::vector;

vector<float> filter(vector<float> values, int inputSize, int filterSize, vector<float> (*filterFunction)(vector<float>, int, int))
{
    // if (filterSize > inputSize)
    //     throw std::invalid_argument("filterSize should be less than or equal to inputSize\n");
    // if (filterSize <= 0)
    //     throw std::invalid_argument("filterSize should be greater than zero\n");
    assert(filterSize <= inputSize);
    assert(filterSize > 0);
    assert((filterSize % 2) != 0);

    return filterFunction(values, inputSize, filterSize);
}

vector<float> averageFilter(vector<float> values, int inputSize, int filterSize)
{
    vector<float> output(inputSize);

    float currentFilteredValue = 0;
    int paddingWidth = filterSize / 2;

    // calculating the first filter value
    for (int i = 0; i < filterSize; i++)
    {
        currentFilteredValue += values[i];
    }
    output[paddingWidth] = currentFilteredValue / filterSize;

    // from 2nd filter value
    for (int i = filterSize; i < inputSize; i++)
    {
        currentFilteredValue = currentFilteredValue - values[i - filterSize] + values[i];
        output[i - paddingWidth] = currentFilteredValue / filterSize;
    }

    return output;
}

vector<float> paddedAverageFilter(vector<float> values, int inputSize, int filterSize)
{
    int outputSize = inputSize;
    int paddedInputSize = outputSize + filterSize - 1;
    int paddingWidth = filterSize / 2;

    vector<float> output(outputSize);
    vector<float> paddedValues(paddedInputSize);

    for (int i = 0; i < paddedInputSize; i++)
    {
        if (i < paddingWidth || i >= (inputSize + paddingWidth))
        {
            paddedValues[i] = 0;
            continue;
        }
        paddedValues[i] = values[i - paddingWidth];
    }

    float currentFilteredValue = 0;

    // calculating the first filter value
    for (int i = 0; i < filterSize; i++)
    {
        currentFilteredValue += paddedValues[i];
    }
    output[0] = currentFilteredValue / filterSize;

    // from 2nd filter value
    for (int i = filterSize; i < paddedInputSize; i++)
    {
        currentFilteredValue = currentFilteredValue - paddedValues[i - filterSize] + paddedValues[i];
        output[i - filterSize + 1] = currentFilteredValue / filterSize;
    }

    return output;
}

vector<float> medianFilter(vector<float> values, int inputSize, int filterSize)
{
    vector<float> output(inputSize);

    int paddingWidth = filterSize / 2;

    vector<float> window(filterSize);

    for (int i = 0; i < (inputSize - filterSize + 1); i++)
    {
        for (int j = 0; j < filterSize; j++)
        {
            window[j] = values[i + j];
        }

        sort(window.begin(), window.end());
        // insertionSort(window);
        // quickSort(window, 0, filterSize - 1);

        output[i + paddingWidth] = window[filterSize / 2];

        // using custom quick select 
        // output[i] = findMedian(window, 0 , filterSize - 1, filterSize / 2);
    }

    return output;
}

vector<float> paddedMedianFilter(vector<float> values, int inputSize, int filterSize)
{
    int outputSize = inputSize;
    int paddedInputSize = outputSize + filterSize - 1;
    int paddingWidth = filterSize / 2;

    vector<float> output(outputSize);
    vector<float> paddedValues(paddedInputSize);

    vector<float> window(filterSize);

    for (int i = 0; i < paddedInputSize; i++)
    {
        if (i < paddingWidth || i >= (inputSize + paddingWidth))
        {
            paddedValues[i] = 0;
            continue;
        }
        paddedValues[i] = values[i - paddingWidth];
    }

    for (int i = 0; i < outputSize; i++)
    {
        for (int j = 0; j < filterSize; j++)
        {
            window[j] = paddedValues[i + j];
        }

        sort(window.begin(), window.end());

        output[i] = window[filterSize / 2];
    }

    return output;
}

vector<float> paddedMedianFilterWithStdNthElement(vector<float> values, int inputSize, int filterSize)
{
    int outputSize = inputSize;
    int paddedInputSize = outputSize + filterSize - 1;
    int paddingWidth = filterSize / 2;

    vector<float> output(outputSize);
    vector<float> paddedValues(paddedInputSize);

    vector<float> window(filterSize);

    for (int i = 0; i < paddedInputSize; i++)
    {
        if (i < paddingWidth || i >= (inputSize + paddingWidth))
        {
            paddedValues[i] = 0;
            continue;
        }
        paddedValues[i] = values[i - paddingWidth];
    }

    for (int i = 0; i < outputSize; i++)
    {
        for (int j = 0; j < filterSize; j++)
        {
            window[j] = paddedValues[i + j];
        }

        std::nth_element(window.begin(), window.begin() + (filterSize / 2), window.end());

        output[i] = window[filterSize / 2];
    }

    return output;
}