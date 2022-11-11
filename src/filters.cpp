// 1D median filter implementation
// Time: O(n)
// Space: O(n) corrresponding to input size
// by Maneesh Sutar

#include <vector>
#include <algorithm>
#include <assert.h>
// #include <iostream>

#include "../include/helpers.hpp"

// using namespace std;
using std::vector;

vector<float> filter(vector<float> values, int inputSize, int filterSize,  vector<float> (*filterFunction)(vector<float>, int, int))
{
    // if (filterSize > inputSize)
    //     throw std::invalid_argument("filterSize should be less than or equal to inputSize\n");
    // if (filterSize <= 0)
    //     throw std::invalid_argument("filterSize should be greater than zero\n");
    assert(filterSize <= inputSize);
    assert(filterSize > 0);

    return filterFunction(values, inputSize, filterSize);
}

vector<float> averageFilter(vector<float> values, int inputSize, int filterSize)
{
    int outputSize = inputSize - filterSize + 1;
    vector<float> output(outputSize);

    float currentFilteredValue = 0;

    // calculating the first filter value
    for (int i = 0; i < filterSize; i++)
    {
        currentFilteredValue += values[i];
    }
    output[0] = currentFilteredValue / filterSize;

    // from 2nd filter value
    for (int i = filterSize; i < inputSize; i++)
    {
        currentFilteredValue = currentFilteredValue - values[i - filterSize] + values[i];
        output[i - filterSize + 1] = currentFilteredValue / filterSize;
    }

    return output;
}

vector<float> paddedAverageFilter(vector<float> values, int inputSize, int filterSize)
{
    assert((filterSize % 2) != 0);

    int outputSize = inputSize;
    int paddedInputSize = outputSize + filterSize - 1;
    int paddingWidth = filterSize / 2;

    vector <float> output(outputSize);
    vector <float> paddedValues(paddedInputSize);

    for (int i = 0; i < paddedInputSize; i++)
    {
        if (i < paddingWidth || i >= (inputSize+paddingWidth))
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

    int outputSize = inputSize - filterSize + 1;
    vector<float> output(outputSize);

    vector<float> window(filterSize);

    for (int i = 0; i < outputSize; i++)
    {
        for (int j = 0; j < filterSize; j++)
        {
            window[j] = values[i + j];
        }

        sort(window.begin(), window.end());
        //        insertionSort(window, filterSize);

        if (filterSize % 2 != 0)
        {
            output[i] = window[filterSize / 2];
        }
        else
        {
            output[i] = (window[filterSize / 2] + window[filterSize / 2 - 1]) / 2;
        }
    }

    return output;
}

vector<float> paddedMedianFilter(vector<float> values, int inputSize, int filterSize){

    assert((filterSize % 2) != 0);

    int outputSize = inputSize;
    int paddedInputSize = outputSize + filterSize - 1;
    int paddingWidth = filterSize / 2;

    vector<float> output(outputSize);
    vector <float> paddedValues(paddedInputSize);

    float window[filterSize];

    for (int i = 0; i < paddedInputSize; i++)
    {
        if (i < paddingWidth || i >= (inputSize+paddingWidth))
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

        std::sort(window, window + filterSize);
        //        insertionSort(window, filterSize);

        if (filterSize % 2 != 0)
        {
            output[i] = window[filterSize / 2];
        }
        else
        {
            output[i] = (window[filterSize / 2] + window[filterSize / 2 - 1]) / 2;
        }
    }

    return output;
}

// O(N) Median Filter
// https://rcoh.me/posts/linear-time-median-finding/

float findMedian(vector<float> window, int index)
{
    // TODO
    if (window.size() <= 1)
        return window.at(0);

    int pivot = generateRandomNumberInRange(0, (unsigned)window.size());

    vector<float> lows, highs, pivots;

    for (int i = 0; i < window.size(); i++)
    {
        if (window[i] < pivot)
            lows.push_back(window[i]);
        else if (window[i] > pivot)
            highs.push_back(window[i]);
        else
            pivots.push_back(window[i]);
    }

    if (index < lows.size())
        return findMedian(lows, index);

    if (index < lows.size() + pivots.size())
        return pivots.at(0);

    return findMedian(highs, index - (int)lows.size() - (int)pivots.size());
}

// undestand this algorithm
vector<float> efficientMedianFilter(vector<float> values, int inputSize, int filterSize)
{

    int outputSize = inputSize - filterSize + 1;
    vector<float> output(outputSize);

    vector<float> window(filterSize);

    for (int i = 0; i < outputSize; i++)
    {
        for (int j = 0; j < filterSize; j++)
        {
            window[j] = values[i + j];
        }

        if (filterSize % 2 != 0)
        {
            output[i] = findMedian(window, filterSize / 2);
        }
        else
        {
            output[i] = 0.5 * (findMedian(window, filterSize / 2) +
                               findMedian(window, filterSize / 2 - 1));
        }
    }

    return output;
}
