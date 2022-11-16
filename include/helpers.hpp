#ifndef include_helpers_hpp
#define include_helpers_hpp

#include <vector>
#include <chrono>

namespace chrono = std::chrono;

int generateRandomNumberInRange(int lower, int upper);

void printArray(float *input, int inputSize);

void insertionSort(std::vector<float> window);

int partition(std::vector<float> v, int start, int end);

void quickSort(std::vector<float> window, int start, int back);

float findMedian(std::vector<float> window,  int start, int back,  int medianIndex);

class Timer {
private:
  chrono::time_point<chrono::system_clock> start;
  chrono::time_point<chrono::system_clock> end;

public:
  void start_timer() { this->start = chrono::system_clock::now(); }
  void stop_timer() { this->end = chrono::system_clock::now(); }

  auto time_elapsed() {
    return chrono::duration_cast<chrono::microseconds>(this->end - this->start)
        .count();
  }
};

#endif /* include_helpers_hpp */
