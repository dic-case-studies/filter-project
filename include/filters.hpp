// 1D median filter implementation

#ifndef filters_h
#define filters_h

#include <vector>

float* filter(int inputSize, int filterSize, float *values, float* (*filterFunction)(int,int,float*));

float* averageFilter(int inputSize, int filterSize, float* values) ;

float* paddedAverageFilter(int inputSize, int filterSize, float* values ) ;

float* medianFilter(int inputSize, int filterSize, float* values);

float* paddedMedianFilter(int inputSize, int filterSize, float *values);

float findMedian(std::vector<float> window, int index);

float* efficientMedianFilter(int inputSize, int filterSize, float* values);






#endif // filters_h
