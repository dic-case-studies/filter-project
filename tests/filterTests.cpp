#include "filters.hpp"

#include <assert.h>
#include <gtest/gtest.h>
#include <vector>

using std::vector;

TEST(filterTests, shouldReturnAverageFilteredValuesWhenInputIsProvided)
{
    int inputSize, filterSize;

    inputSize = 10;
    filterSize = 5;

    vector<float> expectedOutput{0, 0, 3, 4, 5, 6, 7, 8, 0, 0};

    vector<float> input{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    vector<float> output = filter(input, inputSize, filterSize, averageFilter);

    EXPECT_EQ(output.size(), expectedOutput.size());
    for (int i = 0; i < output.size(); i++)
    {
        EXPECT_EQ(output[i] , expectedOutput[i]);
    }
}

TEST(filterTests, shouldReturnMedianFilteredValuesWhenInputIsProvided)
{
    int inputSize, filterSize;

    inputSize = 10;
    filterSize = 5;

    vector<float> expectedOutput{0, 0, 3, 4, 5, 6, 7, 8, 0, 0};

    vector<float> input{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    vector<float> output = filter(input, inputSize, filterSize, medianFilter);

    EXPECT_EQ(output.size(), expectedOutput.size());
    for (int i = 0; i < output.size(); i++)
    {
        EXPECT_EQ(output[i] , expectedOutput[i]);
    }
}

TEST(filterTests, shouldReturnPaddedAverageFilteredValuesWhenInputIsProvided)
{
    int inputSize, filterSize;

    inputSize = 10;
    filterSize = 5;

    vector<float> input{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<float> expectedOutput{1.2, 2, 3, 4, 5, 6, 7, 8, 6.8, 5.4};

    vector<float> output;
    output = filter(input, inputSize, filterSize, paddedAverageFilter);

    EXPECT_EQ(output.size(), expectedOutput.size());
    for (int i = 0; i < output.size(); i++)
    {
        EXPECT_EQ(output[i] , expectedOutput[i]);
    }
}

TEST(filterTests, shouldReturnPaddedMedianFilteredValuesWhenInputIsProvided)
{
    int inputSize, filterSize;

    inputSize = 10;
    filterSize = 5;

    vector<float> input{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<float> expectedOutput{1, 2, 3, 4, 5, 6, 7, 8, 8, 8};

    vector<float> output;
    output = filter(input, inputSize, filterSize, paddedMedianFilter);

    EXPECT_EQ(output.size(), expectedOutput.size());
    for (int i = 0; i < output.size(); i++)
    {
        EXPECT_EQ(output[i] , expectedOutput[i]);
    }
}

TEST(filterTests, shouldReturnMedianFilteredValuesWithStdNthElementFunctionWhenInputIsProvided)
{
    int inputSize, filterSize;

    inputSize = 10;
    filterSize = 5;

    vector<float> input{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<float> expectedOutput{0, 0, 3, 4, 5, 6, 7, 8, 0, 0};

    vector<float> output;
    output = filter(input, inputSize, filterSize, medianFilterWithStdNthElementFunction);

    EXPECT_EQ(output.size(), expectedOutput.size());
    for (int i = 0; i < output.size(); i++)
    {
        EXPECT_EQ(output[i] , expectedOutput[i]);
    }
}

TEST(filterTests, shouldReturnAverageTwoDFilteredValuesWhenInputIsProvided)
{
    int inputSize, filterSize;

    inputSize = 4;
    filterSize = 3;

    vector<vector<float>> input{{1, 1, 1, 1},
                                {2, 2, 2, 2},
                                {3, 3, 3, 3},
                                {4, 4, 4, 4}};

    vector<vector<float>> expectedOutput{{0, 0, 0, 0},
                                         {0, 2, 2, 0},
                                         {0, 3, 3, 0},
                                         {0, 0, 0, 0}};

    vector<vector<float>> output;

    output = filter(input, filterSize, twoDAverageFilter);

    for (int i = 0; i < inputSize; i++)
    {
        for (int j = 0; j < inputSize; j++)
        {
            EXPECT_EQ(output[i][j], expectedOutput[i][j]);
        }
    }
}
