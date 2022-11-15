#ifndef include_filters_hpp
#define include_filters_hpp

#include <vector>

std::vector<float> filter(std::vector<float> values, int inputSize, int filterSize, std::vector<float> (*filterFunction)(std::vector<float>, int, int));

std::vector<float> averageFilter(std::vector<float> values, int inputSize, int filterSize);

std::vector<float> paddedAverageFilter(std::vector<float> values, int inputSize, int filterSize);

std::vector<float> medianFilter(std::vector<float> values, int inputSize, int filterSize);

std::vector<float> paddedMedianFilter(std::vector<float> values, int inputSize, int filterSize);

std::vector<float> medianFilterWithStdNthElementFunction(std::vector<float> values, int inputSize, int filterSize);

#endif /* include_filters_hpp */
