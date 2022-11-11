// 1D median filter implementation

#ifndef filters_h
#define filters_h

#include <vector>

std::vector<float> filter(float *values, int inputSize, int filterSize, std::vector<float> (*filterFunction)(float*,int,int));

std::vector<float> averageFilter(float *values, int inputSize, int filterSize) ;

std::vector<float> paddedAverageFilter(float *values, int inputSize, int filterSize) ;

std::vector<float> medianFilter(float *values, int inputSize, int filterSize);

std::vector<float> paddedMedianFilter(float *values, int inputSize, int filterSize);

float findMedian(std::vector<float> window, int index);

std::vector<float> efficientMedianFilter(float *values, int inputSize, int filterSize);


#endif // filters_h
