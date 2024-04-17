 //Q2.Write a program in C/C++/ Java to sort a given set of elements using the Quick sort method and determine the time required to sort the elements. Repeat the experiment for different values of n, the number of elements in the list to be sorted. The elements can be read from a file or can be generated using the random number generator.
//Sol
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
       quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main() {
    srand(time(0));
    for (int n = 1000; n <= 10000; n += 1000) {
        int arr[n];
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 10000; // Generate random numbers
        }
        clock_t start = clock();
        quickSort(arr, 0, n - 1);
        clock_t end = clock();
        double time_taken = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken to sort " << n << " elements: " << time_taken << " seconds" << endl;
    }
    return 0;
}
