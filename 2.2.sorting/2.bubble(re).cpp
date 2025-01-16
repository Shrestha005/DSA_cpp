#include <bits/stdc++.h>
using namespace std;


// Brute
// void bubble_sort(int arr[], int n) {
//     if (n == 1) return; // Base Case
//     for (int i = 0; i <= n - 2; i++) {
//         if (arr[i] > arr[i + 1]) {
//             int temp = arr[i + 1];
//             arr[i + 1] = arr[i];
//             arr[i] = temp;
//         }
//     }
//     bubble_sort(arr, n - 1);
// }
// int main()
// {
//     int arr[] = {13, 46, 24, 52, 20, 9};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     cout << "Before Using Bubble Sort: " << endl;
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     bubble_sort(arr, n);
//     cout << "After Using bubble sort: " << "\n";
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << "\n";
//     return 0;
// }

// Optimal
void bubble_sort(int arr[], int n) {
    if (n == 1) return; // Base Case
    int didSwap = 0;
    for (int j = 0; j <= n - 2; j++) {
        if (arr[j] > arr[j + 1]) {
            int temp = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = temp;
            didSwap = 1;
        }
    }
    if (didSwap == 0) return;
    bubble_sort(arr, n - 1);
}
int main()
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Using Bubble Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    bubble_sort(arr, n);
    cout << "After Using bubble sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}