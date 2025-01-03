#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int lo, int hi) {
    int pivot = arr[lo];
    int i = lo;
    int j = hi;

    while (i < j) {
        while (arr[i] <= pivot && i <= hi - 1) {
            i++;
        }

        while (arr[j] > pivot && j >= lo + 1) {
            j--;
        }
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[lo], arr[j]);
    return j;
}

// pIndex is the partition index
void qs(vector<int> &arr, int lo, int hi) {
    if (lo < hi) {
        int pIndex = partition(arr, lo, hi);
        qs(arr, lo, pIndex - 1);
        qs(arr, pIndex + 1, hi);
    }
}

vector<int> quickSort(vector<int> arr) {
    qs(arr, 0, arr.size() - 1);
    return arr;
}

int main()
{
    vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
    int n = arr.size();
    cout << "Before Using quick Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr = quickSort(arr);
    cout << "After Using quick sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}
