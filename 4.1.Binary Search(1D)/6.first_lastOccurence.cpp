#include <bits/stdc++.h>
using namespace std;

// Method 1(using lb, ub)
// first occurence is lower bound index
// last occurence is (upper bound - 1) index

// int lowerBound(int arr[], int n, int x){
//     int low= 0, high= n-1;
//     int ans= n;
//     while (low <= high)
//     {
//         int mid= (low+high)/2;

//         if(arr[mid] >= x){
//             ans= mid;
//             high= mid-1;
//         }
//         else{
//             low= mid+1;
//         }
//     }
//     return ans;
// }
// int upperBound(int arr[], int n, int x){
//     int low= 0, high= n-1;
//     int ans= n;
//     while (low<=high)
//     {
//         int mid= (low+high)/2;
//         if(arr[mid] > x){
//             ans= mid;
//             high= mid-1;
//         }
//         else{
//             low= mid+1;
//         }
//     }
//     return ans;
// }
// pair<int, int> firstAndLastOccurence(int arr[], int n, int k){
//     int lb= lowerBound(arr, n ,k);
//     if(lb==n || arr[lb]!=k) return {-1,-1};
//     return {lb , upperBound(arr,n,k)-1};
// }
// int main() {
//     int a[] = {3, 4, 13, 13, 13, 20, 40};
//     int n = 7;
//     int target = 13;
//     pair<int, int> result = firstAndLastOccurence(a, n, target);
//     cout << "First Occurrence: " << result.first << ", Last Occurrence: " << result.second << "\n";
//     return 0;
// }


// Method 2(using BS)
int firstOccurence(vector<int> arr, int n, int x){
    int low= 0, high= n-1;
    int first= -1;
    while (low<=high)
    {
        int mid= (low+high)/2;
        if(arr[mid]==x){
            first=mid;
            high= mid-1;
        }
        else if(arr[mid]>x) high= mid-1;
        else low= mid+1;
    }
    return first;
}
int lastOccurence(vector<int> arr, int n, int x){
    int low= 0, high= n-1;
    int last= -1;
    while (low<=high)
    {
        int mid= (low+high)/2;
        if(arr[mid]==x){
            last=mid;
            low= mid+1;
        }
        else if(arr[mid]>x) high= mid-1;
        else low= mid+1;
    }
    return last;
}
pair<int,int> firstAndLastOccurence(vector<int> &arr, int n, int k){
    int first= firstOccurence(arr, n, k);
    if(first==-1) return {-1,-1};
    int last= lastOccurence(arr, n, k);
    return {first,last};
}
int main() {
    vector<int> a = {3, 4, 13, 13, 13, 20, 40};
    int n = 7;
    int target = 13;
    pair<int, int> result = firstAndLastOccurence(a, n, target);
    cout << "First Occurrence: " << result.first << ", Last Occurrence: " << result.second << "\n";
    return 0;
}