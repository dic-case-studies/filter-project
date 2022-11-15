#include "helpers.hpp"

#include <algorithm>
#include <assert.h>
#include <vector>

using std::vector;

vector<float> filter(vector<float> values, int filterSize, vector<float> (*filterFunction)(vector<float>, int))
{
    assert(filterSize <= values.size());
    assert(filterSize > 0);
    assert((filterSize % 2) != 0);

    return filterFunction(values, filterSize);
}

// vector<vector<float>> filter(vector<vector<float>> values, int filterSize, vector<vector<float>> (*filterFunction)(vector<vector<float>>, int))
// {
//     assert(filterSize <= values.size());
//     assert(filterSize > 0);
//     assert((filterSize % 2) != 0);

//     return filterFunction(values, filterSize);
// }

vector<float> twoDAverageFilter(vector<float> values, int filterSize)
{
    // int row = values.size();
    // int col = values[0].size();

    vector<float> output(values.size(), 0);

    float windowSum;

    for (int r = 0; r < values.size(); r=r+filterSize)
    {
        for (int c = 0; c < filterSize / 2; c++)
        {
            windowSum = 0;

            for (int rr = 0; rr < filterSize; rr++)
            {
                for (int cc = 0; cc < filterSize; cc++)
                {
                    windowSum += values[r + rr - 1][c + cc - 1];
                }
            }

            output[r][c] = windowSum / (filterSize * filterSize);
        }
    }

    return output;
}

vector<float> averageFilter(vector<float> values, int filterSize)
{
    vector<float> output(values.size());

    float currentFilteredValue = 0;
    int paddingWidth = filterSize / 2;

    // calculating the first filter value
    for (int i = 0; i < filterSize; i++)
    {
        currentFilteredValue += values[i];
    }
    output[paddingWidth] = currentFilteredValue / filterSize;

    // from 2nd filter value
    for (int i = filterSize; i < values.size(); i++)
    {
        currentFilteredValue = currentFilteredValue - values[i - filterSize] + values[i];
        output[i - paddingWidth] = currentFilteredValue / filterSize;
    }

    return output;
}

// input padded
vector<float> paddedAverageFilter(vector<float> values, int filterSize)
{
    int outputSize = values.size();
    int paddedInputSize = outputSize + filterSize - 1;
    int paddingWidth = filterSize / 2;

    vector<float> output(outputSize);
    vector<float> paddedValues(paddedInputSize);

    for (int i = 0; i < paddedInputSize; i++)
    {
        if (i < paddingWidth || i >= (values.size() + paddingWidth))
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

vector<float> medianFilter(vector<float> values, int filterSize)
{
    vector<float> output(values.size());

    int paddingWidth = filterSize / 2;

    vector<float> window(filterSize);

    for (int i = 0; i < (values.size() - filterSize + 1); i++)
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

// input paded
vector<float> paddedMedianFilter(vector<float> values, int filterSize)
{
    int outputSize = values.size();
    int paddedInputSize = outputSize + filterSize - 1;
    int paddingWidth = filterSize / 2;

    vector<float> output(outputSize);
    vector<float> paddedValues(paddedInputSize);

    vector<float> window(filterSize);

    for (int i = 0; i < paddedInputSize; i++)
    {
        if (i < paddingWidth || i >= (values.size() + paddingWidth))
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

vector<float> medianFilterWithStdNthElementFunction(vector<float> values, int filterSize)
{
    vector<float> output(values.size());

    int paddingWidth = filterSize / 2;

    vector<float> window(filterSize);

    for (int i = 0; i < (values.size() - filterSize + 1); i++)
    {
        for (int j = 0; j < filterSize; j++)
        {
            window[j] = values[i + j];
        }

        std::nth_element(window.begin(), window.begin() + (filterSize / 2), window.end());

        output[i + paddingWidth] = window[filterSize / 2];
    }

    return output;
}