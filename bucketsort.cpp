#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucketSort(float arr[], int n) {
    vector<float> b[10];

    for (int i = 0; i < n; i++) {
        int index = n * arr[i];
        if (index >= n) index = n - 1;
        b[index].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        sort(b[i].begin(), b[i].end());
    }

    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < b[i].size(); j++) {
            arr[k++] = b[i][j];
        }
    }
}

int main() {
    float arr[] = {0.42, 0.32, 0.23, 0.52, 0.25};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}