// Problem concept: in pairs left ele has to be greater than 2*right ele
#include <bits/stdc++.h>
using namespace std;

// Brute
// int countPairs(vector<int>&a, int n) {
//     int cnt = 0;
//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             if (a[i] > 2 * a[j]) cnt++;
//         }
//     }
//     return cnt;
// }
// int main()
// {
//     vector<int> a = {4, 1, 2, 3, 1};
//     int n = 5;
//     int cnt = countPairs(a, n);
//     cout << "The number of reverse pair is: "
//          << cnt << endl;
//     return 0;
// }

// Optimal

void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;      
    int right = mid + 1;   
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}


//new function used in main function reversePairs
int countPairs(vector<int> &arr, int low, int mid, int high) {
    int right = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++) {
        while (right <= high && arr[i] > 2 * arr[right]) right++;
        cnt += (right - (mid + 1));
    }
    return cnt;
}
int mergeSort(vector<int> &arr, int low, int high) {
    int cnt=0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
    cnt+= mergeSort(arr, low, mid);  
    cnt+= mergeSort(arr, mid + 1, high); 
    cnt+= countPairs(arr, low, mid, high); //only new function added with merge sort
    merge(arr, low, mid, high); 
    return cnt;
}
int reversePairs(vector<int> &arr, int n){ //main function
    return mergeSort(arr, 0, n-1);
}
int main()
{
    vector<int> a = {4, 1, 2, 3, 1};
    int n = 5;
    int cnt = reversePairs(a, n);
    cout << "The number of reverse pair is: "
         << cnt << endl;
    return 0;
}