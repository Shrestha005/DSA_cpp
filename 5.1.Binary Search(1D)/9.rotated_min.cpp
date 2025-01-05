#include <bits/stdc++.h>
using namespace std;

// Brute(linear search)
// int findMin(vector<int>& arr){
//     int n = arr.size(); // size of the array.
//     int mini = INT_MAX;
//     for (int i = 0; i < n; i++) {
//         // Always keep the minimum.
//         mini = min(mini, arr[i]);
//     }
//     return mini;
// }

// Optimal 1(BS)
int findMin(vector<int>& arr){
    int n= arr.size();
    int low=0, high= n-1;
    int mini= INT_MAX;
    while (low<=high)
    {
        int mid= (low+high)/2;
        //left sorted
        if(arr[low]<=arr[mid]){
            mini= min(arr[low], mini);
            low= mid+1;
        }
         //right sorted
        else{
            mini= min(arr[mid], mini);
            high= mid-1;
        }
    }
    return mini;
}
int main()
{
    vector<int> arr = {4, 5, 6, 7, 1, 2, 3};
    int ans = findMin(arr);
    cout << "The minimum element is: " << ans << "\n";
    return 0;
}


// Optimal 2(BS more optimized)
// int findMin(vector<int>& arr){
//     int n= arr.size();
//     int low=0, high= n-1;
//     int mini= INT_MAX;
//     while (low<=high)
//     {
//         int mid= (low+high)/2;
//         if(arr[low]<=arr[high]){
//             mini=min(arr[low],mini);
//              break;
//         }
//         //left sorted
//         if(arr[low]<=arr[mid]){
//             mini= min(arr[low], mini);
//             low= mid+1;
//         }
//         //right sorted
//         else{
//             mini= min(arr[mid], mini);
//             high= mid-1;
//         }
//     }
//     return mini;
// }
// int main()
// {
//     vector<int> arr = {4, 5, 6, 7, 1, 2, 3};
//     int ans = findMin(arr);
//     cout << "The minimum element is: " << ans << "\n";
//     return 0;
// }
