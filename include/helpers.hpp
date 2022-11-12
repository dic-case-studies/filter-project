#ifndef helpers_hpp
#define helpers_hpp

#include <vector>

int generateRandomNumberInRange(int lower, int upper);

void printArray(float *input, int inputSize);

void insertionSort(std::vector<float> window);

int partition(std::vector<float> v, int start, int end);

void quickSort(std::vector<float> window, int start, int back);

float findMedian(std::vector<float> window,  int start, int back,  int medianIndex);

#endif /* helpers_hpp */
