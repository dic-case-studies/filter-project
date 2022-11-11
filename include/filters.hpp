// 1D median filter implementation

#ifndef filters_h
#define filters_h

#include <vector>

std::vector<float> filter(std::vector<float> values, int inputSize, int filterSize, std::vector<float> (*filterFunction)(std::vector<float>,int,int));

std::vector<float> averageFilter(std::vector<float> values, int inputSize, int filterSize) ;

std::vector<float> paddedAverageFilter(std::vector<float> values, int inputSize, int filterSize) ;

std::vector<float> medianFilter(std::vector<float> values, int inputSize, int filterSize);

std::vector<float> paddedMedianFilter(std::vector<float> values, int inputSize, int filterSize);

std::vector<float> paddedMedianFilterWithStdNthElement(std::vector<float> values, int inputSize, int filterSize);

float findMedian(std::vector<float> window, int index);

std::vector<float> efficientMedianFilter(std::vector<float> values, int inputSize, int filterSize);


#endif // filters_h
