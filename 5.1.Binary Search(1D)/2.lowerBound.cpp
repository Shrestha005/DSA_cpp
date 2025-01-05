
#include <bits/stdc++.h>
using namespace std;

// Brute

// int lowerBound(vector<int> arr, int n, int x) {
//     for (int i = 0; i < n; i++) {
//         if (arr[i] >= x) {
//             // lower bound found:
//             return i;
//         }
//     }
//     return n;
// }
// int main()
// {
//     vector<int> arr = {3, 5, 8, 15, 19};
//     int n = 5, x = 9;
//     int ind = lowerBound(arr, n, x);
//     cout << "The lower bound is the index: " << ind << "\n";
//     return 0;
// }

// Optimal

int lowerBound(vector<int> arr, int n, int x){
    int low= 0, high= n-1;
    int index= n;
    while (low <= high)
    {
        int mid= (low+high)/2;

        if(arr[mid] >= x){
            index= mid;
            high= mid-1;
        }
        else{
            low= mid+1;
        }
    }
    return index;
}
int main()
{
    vector<int> arr = {3, 5, 8, 15, 19};
    int n = 5, x = 9;
    int ind = lowerBound(arr, n, x);
    cout << "The lower bound is the index: " << ind << "\n";
    return 0;
}

// IMPORTANT!
// For coding rounds:
// int lb= lower_bound(arr.begin() , arr.end() , target);

// to get the index= lower_bound(arr.begin() , arr.end() , target) - arr.begin()

// If a lb is to be found in a particular given range of index in an array 
// Eg: from 2nd index to 6th index [traverse from index 2 to 7]
// lower_bound(arr+2 , arr+7 , target) - arr.begin()