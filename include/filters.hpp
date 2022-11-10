// 1D median filter implementation

#ifndef filters_h
#define filters_h

#include <vector>

std::vector<float> filter(int inputSize, int filterSize, float *values, std::vector<float> (*filterFunction)(int,int,float*));

std::vector<float> averageFilter(int inputSize, int filterSize, float* values) ;

std::vector<float> paddedAverageFilter(int inputSize, int filterSize, float* values ) ;

std::vector<float> medianFilter(int inputSize, int filterSize, float* values);

std::vector<float> paddedMedianFilter(int inputSize, int filterSize, float *values);

float findMedian(std::vector<float> window, int index);

std::vector<float> efficientMedianFilter(int inputSize, int filterSize, float* values);


#endif // filters_h
