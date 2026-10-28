#include <iostream>
using namespace std;

void binSort(int arr[], int n) {
    int maxVal = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    int* bin = new int[maxVal + 1]();

    for (int i = 0; i < n; i++) {
        bin[arr[i]]++;
    }

    int j = 0;

    for (int i = 0; i <= maxVal; i++) {
        while (bin[i] > 0) {
            arr[j++] = i;
            bin[i]--;
        }
    }

    delete[] bin;
}

int main() {
    int arr[] = {4, 2, 7, 2, 1, 5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    binSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}