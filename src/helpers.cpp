#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int generateRandomNumberInRange(int lower, int upper)
{
    return (rand() % (upper - lower + 1)) + lower;
}

void printArray(float *input, int inputSize)
{
    for (int i = 0; i < inputSize; i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;
}

// implement sort function
void insertionSort(vector<float> vec)
{
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        // Searching the upper bound, i.e., first
        // element greater than *it from beginning
        auto const insertion_point =
            std::upper_bound(vec.begin(), it, *it);

        // Shifting the unsorted part
        std::rotate(insertion_point, it, it + 1);
    }
}

int partition(vector<float> v, int start, int end)
{
    int pivot = end;
    int j = start;
    for (int i = start; i < end; ++i)
    {
        if (v[i] < v[pivot])
        {
            std::swap(v[i], v[j]);
            ++j;
        }
    }
    std::swap(v[j], v[pivot]);
    return j;
}

void quickSort(vector<float> window, int start, int end)
{
    if (start < end)
    {
        int index = partition(window, start, end);

        quickSort(window, start, index - 1);
        quickSort(window, index + 1, end);
    }
}

// using quick select algorithm
float findMedian(vector<float> window, int start, int back, int medianIndex)
{
    // Partition the array around last
    // element and get position of pivot
    // element in sorted array
    int index = partition(window, start, back);

    // If position is same as k
    if (index - start == medianIndex)
        return window[index];

    // If position is more, recur
    // for left subarray
    if (index - start > medianIndex)
        return findMedian(window, start, index - 1, medianIndex);

    // Else recur for right subarray
    return findMedian(window, index + 1, back, medianIndex - index + 1);
}
