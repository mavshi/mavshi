 

//Q1.Write programs in C/C++/ Java to sort a list of n numbers in ascending order using selection sort, insertion sort, heap sort, radix sort. Determine the time required to sort and compare on basis of time complexity for different values of n.
//
 // Sol
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    vector<int> count(10, 0);

    for (int i = 0; i < n; ++i) {
        count[(arr[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; --i) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}
void radixSort(vector<int>& arr) {
    int maxElement = *max_element(arr.begin(), arr.end());
    for (int exp = 1; maxElement / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}
double timeSort(void (*sortFunc)(vector<int>&), vector<int>& arr) {
    clock_t start = clock();
    sortFunc(arr);
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}
int main() {
    srand(time(nullptr));
    int n;
 cout << "Enter the number of elements: ";
    cin >> n;
   vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 1000; // generate random numbers between 0 and 999
    }
    cout << "Sorting " << n << " elements...\n";
    vector<int> arr_copy;
   arr_copy = arr;
    cout << "Selection Sort Time: " << timeSort(selectionSort, arr_copy) << " seconds\n";
    arr_copy = arr;
    cout << "Insertion Sort Time: " << timeSort(insertionSort, arr_copy) << " seconds\n";
    arr_copy = arr;
    cout << "Heap Sort Time: " << timeSort(heapSort, arr_copy) << " seconds\n";
    arr_copy = arr;
    cout << "Radix Sort Time: " << timeSort(radixSort, arr_copy) << " seconds\n";
  return 0;
}
