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

// TODO: Fix random amplitude issue
int main(int argc, char const *argv[]) {
  int inputSize, filterSize;

  // run for different values
  // if (argc != 3)
  //     throw std::invalid_argument("provide both inputs");

  // inputSize = std::atoi(argv[1]);
  // filterSize = std::atoi(argv[2]);

  inputSize = 1000;
  filterSize = 9;

  std::vector<float> input(inputSize);
  srand((unsigned)time(0));

  // to generate noise
  const float mean = 0.0;
  const float stddev = 0.2;
  std::default_random_engine generator;
  std::normal_distribution<float> dist(mean, stddev);

  double amplitude = 10;
  float frequency = 5; // Hz
  float shift = 0;

  for (int i = 0; i < inputSize; i++) {
    input[i] = amplitude * sin(2 * M_PI * (frequency / inputSize) * i + shift) +
               dist(generator);
  }

  // writing input to a file
  std::ofstream InputFile("./out/input.txt");

  for (int i = 0; i < inputSize; i++) {
    InputFile << i << " " << input[i] << endl;
  }
  InputFile.close();

  std::vector<float> output;

  auto start = std::chrono::high_resolution_clock::now();

  output = filter(input, filterSize, medianFilter);

  auto stop = std::chrono::high_resolution_clock::now();

  auto duration =
      std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

  std::cout << duration.count() << " us" << std::endl;

  // writing to a output
  std::ofstream OutputFile("./out/output.txt");
  for (int i = 0; i < inputSize; i++) {
    OutputFile << i << " " << output[i] << endl;
  }
  OutputFile.close();

  return 0;
}
