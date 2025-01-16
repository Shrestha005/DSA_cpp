#include <bits/stdc++.h>
using namespace std;

// Method 1(iterative)

// int BS(vector<int> &arr, int target){
//     int n= arr.size();
//     int low= 0, high= n-1;
//     while (low <= high)
//     {
//         int mid= (low + high)/2;
//         if(arr[mid] == target) return mid;
//         else if(target < arr[mid]) high= mid-1;
//         else low= mid+1;
//     }
//     return -1;
// }
// int main()
// {
//     vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
//     int target = 6;
//     int ind = BS(a, target);
//     if (ind == -1) cout << "The target is not present." << endl;
//     else cout << "The target is at index: "
//                   << ind << endl;
//     return 0;
// }


// Method 2(recursive)
int BS(vector<int> &arr, int low, int high, int target){
    if(low > high) return -1;
    int mid= (low + high)/2;
    if(arr[mid] == target) return mid;
    else if(target < arr[mid]) return BS(arr, low, mid-1, target);
    else return BS(arr, mid+1, high, target);
}

int main()
{
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 6;
    int ind = BS(a, 0, a.size()-1, target);
    if (ind == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: "
                  << ind << endl;
    return 0;
}


//if it overflows take mid as, mid= low + (high-low)/2
// or take long long for high low mid