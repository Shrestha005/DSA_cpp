//single element in sorted array (rest all elements repeats)

#include <bits/stdc++.h>
using namespace std;

// Brute 1
// if the either left or right of an element is equal to it, its a duplicate element
// if its neither equal to left nor right then it is the single element
// 3 exception cases:
// 1-the 0th index(to be compared with its next index only)
// 2-the (n-1)th index(to be compared with its previous index only)
// 3-if array has 1 element it neither has its right nor left element so return 0

// int singleNonDuplicate(vector<int>& arr) {
//     int n = arr.size(); //size of the array.
//     if (n == 1) return arr[0];
//     for (int i = 0; i < n; i++) {
//         //first index
//         if (i == 0) {
//             if (arr[i] != arr[i + 1])
//                 return arr[i];
//         }
//         //last index
//         else if (i == n - 1) {
//             if (arr[i] != arr[i - 1])
//                 return arr[i];
//         }
//         else {
//             if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1])
//                 return arr[i];
//         }
//     }
//     return -1;
// }
// int main()
// {
//     vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
//     int ans = singleNonDuplicate(arr);
//     cout << "The single element is: " << ans << "\n";
//     return 0;
// }


// Brute 2 (XOR) -> easy!
// int singleNonDuplicate(vector<int>& arr){
//     int n= arr.size();
//     int ans=0;
//     for (int i = 0; i < n; i++)
//     {
//         ans= ans ^ arr[i];
//     }
//     return ans;
// }
// int main()
// {
//     vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
//     int ans = singleNonDuplicate(arr);
//     cout << "The single element is: " << ans << "\n";
//     return 0;
// }

// Optimal (BS)
int singleNonDuplicate(vector<int>& arr){
    int n= arr.size();
    if(n==1) return arr[0];
    if(arr[0]!=arr[1]) return arr[0];
    if(arr[n-1]!=arr[n-2]) return arr[n-1];
    int low=0, high= n-1;
    while (low<=high)
    {
        int mid= (low+high)/2;
        if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]) return arr[mid];
        //if left half contains all duplicates , single element is in right half , so eleminate left half
        if((mid%2==1 && arr[mid-1]==arr[mid]) || (mid%2==0 && arr[mid+1]==arr[mid])){
            low= mid+1;
        }
        //if right half contains all duplicates , single element is in left half , so eleminate right half
        else{
            high= mid-1;
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    int ans = singleNonDuplicate(arr);
    cout << "The single element is: " << ans << "\n";
    return 0;
}
