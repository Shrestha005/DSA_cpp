#include <bits/stdc++.h>
using namespace std;

// Brute
// void merge(long long arr1[], long long arr2[], int n, int m) {
//     //2 ptsr, 3rd array: 
//     long long arr3[n + m];
//     int left = 0;
//     int right = 0;
//     int index = 0;
//     //Insert into 3rd array
//     while (left < n && right < m) {
//         if (arr1[left] <= arr2[right]) {
//             arr3[index] = arr1[left];
//             left++, index++;
//         }
//         else {
//             arr3[index] = arr2[right];
//             right++, index++;
//         }
//     }
//     // If right ptr reaches the end
//     while (left < n) {
//         arr3[index++] = arr1[left++];
//     }
//     // If left ptr reaches the end
//     while (right < m) {
//         arr3[index++] = arr2[right++];
//     }
//     // again filling back arr1 and arr2 from arr3
//     for (int i = 0; i < n + m; i++) {
//         if (i < n) arr1[i] = arr3[i];
//         else arr2[i - n] = arr3[i];
//     }
// }
// int main()
// {
//     long long arr1[] = {1, 4, 8, 10};
//     long long arr2[] = {2, 3, 9};
//     int n = 4, m = 3;
//     merge(arr1, arr2, n, m);
//     cout << "The merged arrays are: " << "\n";
//     cout << "arr1[] = ";
//     for (int i = 0; i < n; i++) {
//         cout << arr1[i] << " ";
//     }
//     cout << "\narr2[] = ";
//     for (int i = 0; i < m; i++) {
//         cout << arr2[i] << " ";
//     }
//     cout << endl;
//     return 0;
// }

// Optimal 1
// void merge(long long arr1[], long long arr2[], int n, int m) {
//     //2 ptrs
//     int left = n - 1;
//     int right = 0;
//     //Swap until left<right
//     while (left >= 0 && right < m) {
//         if (arr1[left] > arr2[right]) {
//             swap(arr1[left], arr2[right]);
//             left--, right++;
//         }
//         else {
//             break;
//         }
//     }
//     // Sorting arr1 and arr2
//     sort(arr1, arr1 + n);
//     sort(arr2, arr2 + m);
// }
// int main()
// {
//     long long arr1[] = {1, 4, 8, 10};
//     long long arr2[] = {2, 3, 9};
//     int n = 4, m = 3;
//     merge(arr1, arr2, n, m);
//     cout << "The merged arrays are: " << "\n";
//     cout << "arr1[] = ";
//     for (int i = 0; i < n; i++) {
//         cout << arr1[i] << " ";
//     }
//     cout << "\narr2[] = ";
//     for (int i = 0; i < m; i++) {
//         cout << arr2[i] << " ";
//     }
//     cout << endl;
//     return 0;
// }

// Optimal 2(Map method using shell sort)
void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2){
    if(arr1[ind1]>arr2[ind2]){
        swap(arr1[ind1], arr2[ind2]);
    }
}

void merge(long long arr1[], long long arr2[], int n, int m){
    int len= (n+m);
    // int gap = (len + 1) / 2;
    int gap= (len/2)+(len%2);
    while(gap>0){
        int left= 0;
        int right= left+gap;
        while(right<len){
            //left ptr in left arr , right ptr in right arr
            if(left<n && right>=n){
                swapIfGreater(arr1, arr2, left, right-n);
            }
            //both ptr in right arr
            else if(left>=n){
                swapIfGreater(arr2, arr2, left-n, right-n);
            }
            //both ptr in left arr
            else{
                swapIfGreater(arr1, arr1, left, right);
            }
            left++, right++;
        }
        if(gap==1) break;
        gap= (gap/2)+(gap%2);
        // int gap = (gap + 1) / 2;
    }
}
int main()
{
    long long arr1[] = {1, 4, 8, 10};
    long long arr2[] = {2, 3, 9};
    int n = 4, m = 3;
    merge(arr1, arr2, n, m);
    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}

