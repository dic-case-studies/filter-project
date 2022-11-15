#ifndef include_filters_hpp
#define include_filters_hpp

#include <vector>

std::vector<float> filter(std::vector<float> values, int filterSize, std::vector<float> (*filterFunction)(std::vector<float>, int));

std::vector<std::vector<float>> filter(std::vector<std::vector<float>> values, int filterSize, std::vector<std::vector<float>> (*filterFunction)(std::vector<std::vector<float>>, int));

std::vector<std::vector<float>> twoDAverageFilter(std::vector<std::vector<float>> values, int filterSize);

std::vector<float> averageFilter(std::vector<float> values, int filterSize);

std::vector<float> paddedAverageFilter(std::vector<float> values, int filterSize);

std::vector<float> medianFilter(std::vector<float> values, int filterSize);

std::vector<float> paddedMedianFilter(std::vector<float> values, int filterSize);

std::vector<float> medianFilterWithStdNthElementFunction(std::vector<float> values, int filterSize);

#endif /* include_filters_hpp */
