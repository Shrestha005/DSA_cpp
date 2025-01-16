#include <bits/stdc++.h>
using namespace std;

// Brute
// int findPeakElement(vector<int> &arr) {
//     int n = arr.size();
//     for (int i = 0; i < n; i++) {
//         if ((i == 0 || arr[i - 1] < arr[i])
//                 && (i == n - 1 || arr[i] > arr[i + 1])) {
//             return i;
//         }
//     }
//     return -1;
// }
// int main()
// {
//     vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
//     int ans = findPeakElement(arr);
//     cout << "The peak is at index: " << ans << "\n";
//     return 0;
// }

// Optimal(BS)
int findPeakElement(vector<int> &arr){
    int n= arr.size();
    int low= 0, high= n-1;
    if(n==1) return arr[0];
    if(arr[0]>arr[1]) return arr[0];
    if(arr[n-1]>arr[n-2]) return arr[n-1];
    while (low<=high)
    {
        int mid= (low+high)/2;

        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;

        //if we are in left
        if(arr[mid]<arr[mid+1] || arr[mid]>arr[mid-1]){
            low= mid+1;
        }
        //if we are in right
        else{
            high= mid-1;
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int ans = findPeakElement(arr);
    cout << "The peak element index is: " << ans << "\n";
    return 0;
}