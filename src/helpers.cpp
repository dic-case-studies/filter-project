
#include <iostream>

using namespace std;

int generateRandomNumberInRange(int lower, int upper)
{
    return (rand() % (upper - lower + 1)) + lower;
}

void printArray(float *input, int inputSize)
{
    for(int i = 0; i < inputSize; i++){
        cout << input[i] << " ";
    }
    cout << endl;
}

// implement sort function
void insertionSort(float arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        // Move elements of arr[0..i-1],
        // that are greater than key, to one
        // position ahead of their
        // current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
