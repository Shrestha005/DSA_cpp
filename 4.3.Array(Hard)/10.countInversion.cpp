#include <bits/stdc++.h>
using namespace std;

// Brute
// int numberOfInversions(vector<int>&a, int n) {
//     int cnt = 0;
//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             if (a[i] > a[j]) cnt++;
//         }
//     }
//     return cnt;
// }
// int main()
// {
//     vector<int> a = {5, 4, 3, 2, 1};
//     int n = 5;
//     int cnt = numberOfInversions(a, n);
//     cout << "The number of inversions is: "
//          << cnt << endl;
//     return 0;
// }


// Optimal(using merge sort)
int cnt=0; //globar var for counting inversions
//Step 1: write merge sort code first:
void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; 
    int left = low;      
    int right = mid + 1;   
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else { //when write is smaller
            temp.push_back(arr[right]);
            cnt += (mid-left+1); //only 1 line new addition to merge sort code for counting inversions
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
void mergeSort(vector<int> &arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2 ;
    mergeSort(arr, low, mid);  
    mergeSort(arr, mid + 1, high); 
    merge(arr, low, mid, high);  
}

//Step 2: main counting inversions code using merge sort
int countOfInversions(vector<int> &arr, int n){
    mergeSort(arr, 0, n-1);
    return cnt;
}
int main()
{
    vector<int> a = {5, 4, 3, 2, 1};
    int n = 5;
    int cnt = countOfInversions(a, n);
    cout << "The number of inversions are: "
         << cnt << endl;
    return 0;
}