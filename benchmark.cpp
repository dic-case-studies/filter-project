#include "filters.hpp"
#include "helpers.hpp"

#include <chrono>
#include <fstream>
#include <iostream>
#include <iterator>
#include <math.h>
#include <random>
#include <string.h>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

Timer stop_watch;

int main(int argc, char const *argv[])
{
    int inputSize, filterSize;

    if (argc != 3)
        throw std::invalid_argument("provide both inputs");

    inputSize = std::atoi(argv[1]);
    filterSize = std::atoi(argv[2]);

    // inputSize = 100;
    // filterSize = 9;
#ifdef TWOD
    vector<vector<float> (*)(vector<float>, int)> filters {twoDAverageFilter,twoDMedianFilter};
    // std::vector<float> input(inputSize * inputSize);
#else
    vector<vector<float> (*)(vector<float>, int)> filters {averageFilter, medianFilter, medianFilterWithStdNthElementFunction};
#endif

    // srand((unsigned)time(0));
    srand(1);

    // to generate noise
    std::vector<float> input(inputSize);
    const float mean = 0.0;
    const float stddev = 0.2;
    std::default_random_engine generator;
    std::normal_distribution<float> dist(mean, stddev);

    double amplitude = generateRandomNumberInRange(3,10);
    float frequency = 1; // Hz
    float shift = 0;

    for (int i = 0; i < inputSize; i++)
    {
        input[i] = amplitude * sin(2 * M_PI * (frequency / inputSize) * i + shift) + dist(generator);
    }

    std::vector<float> output;

    for (int i = 0; i < filters.size(); i++)
    {
        stop_watch.start_timer();
        output = filter(input, filterSize, filters[i]);
        stop_watch.stop_timer();

        auto duration = stop_watch.time_elapsed();

        std::cout << duration << " us" << std::endl;
    }

    return 0;
}
