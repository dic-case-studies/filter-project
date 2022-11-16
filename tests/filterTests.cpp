#include "filters.hpp"

#include <assert.h>
#include <gtest/gtest.h>
#include <vector>

using std::vector;

TEST(filterTests, shouldReturnAverageFilteredValuesWhenInputIsProvided)
{
    int filterSize;

    filterSize = 5;

    vector<float> expectedOutput{0, 0, 3, 4, 5, 6, 7, 8, 0, 0};

    vector<float> input{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    vector<float> output = filter(input, filterSize, averageFilter);

    EXPECT_EQ(output.size(), expectedOutput.size());
    for (int i = 0; i < output.size(); i++)
    {
        EXPECT_EQ(output[i], expectedOutput[i]);
    }
}

TEST(filterTests, shouldReturnMedianFilteredValuesWhenInputIsProvided)
{
    int filterSize;

    filterSize = 5;

    vector<float> expectedOutput{0, 0, 3, 4, 5, 6, 7, 8, 0, 0};

    vector<float> input{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    vector<float> output = filter(input, filterSize, medianFilter);

    EXPECT_EQ(output.size(), expectedOutput.size());
    for (int i = 0; i < output.size(); i++)
    {
        EXPECT_EQ(output[i], expectedOutput[i]);
    }
}

TEST(filterTests, shouldReturnPaddedAverageFilteredValuesWhenInputIsProvided)
{
    int filterSize;

    filterSize = 5;

    vector<float> input{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<float> expectedOutput{1.2, 2, 3, 4, 5, 6, 7, 8, 6.8, 5.4};

    vector<float> output;
    output = filter(input, filterSize, paddedAverageFilter);

    EXPECT_EQ(output.size(), expectedOutput.size());
    for (int i = 0; i < output.size(); i++)
    {
        EXPECT_EQ(output[i], expectedOutput[i]);
    }
}

TEST(filterTests, shouldReturnPaddedMedianFilteredValuesWhenInputIsProvided)
{
    int filterSize;

    filterSize = 5;

    vector<float> input{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<float> expectedOutput{1, 2, 3, 4, 5, 6, 7, 8, 8, 8};

    vector<float> output;
    output = filter(input, filterSize, paddedMedianFilter);

    EXPECT_EQ(output.size(), expectedOutput.size());
    for (int i = 0; i < output.size(); i++)
    {
        EXPECT_EQ(output[i], expectedOutput[i]);
    }
}

TEST(filterTests, shouldReturnMedianFilteredValuesWithStdNthElementFunctionWhenInputIsProvided)
{
    int filterSize;

    filterSize = 5;

    vector<float> input{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<float> expectedOutput{0, 0, 3, 4, 5, 6, 7, 8, 0, 0};

    vector<float> output;
    output = filter(input, filterSize, medianFilterWithStdNthElementFunction);

    EXPECT_EQ(output.size(), expectedOutput.size());
    for (int i = 0; i < output.size(); i++)
    {
        EXPECT_EQ(output[i], expectedOutput[i]);
    }
}

TEST(filterTests, shouldReturnAverageTwoDFilteredValuesWhenInputIsProvided)
{
    int filterSize;

    filterSize = 3;

    vector<float> input{1, 1, 1, 1, 1,
                        2, 2, 2, 2, 2,
                        3, 3, 3, 3, 3,
                        4, 4, 4, 4, 4,
                        5, 5, 5, 5, 5};

    vector<float> expectedOutput{0, 0, 0, 0, 0,
                                 0, 2, 2, 2, 0,
                                 0, 3, 3, 3, 0,
                                 0, 4, 4, 4, 0,
                                 0, 0, 0, 0, 0};

    vector<float> output;

    output = filter(input, filterSize, twoDAverageFilter);

    EXPECT_EQ(output.size(), expectedOutput.size());

    for (int i = 0; i < output.size(); i++)
    {
        EXPECT_EQ(output[i], expectedOutput[i]);
    }
}
