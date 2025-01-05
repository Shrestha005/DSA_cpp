// IMPORTANT!
// index[minimum element in a rotated sorted array] =  number of times the array has been rotated 


// Brute(LS)

// Optimal(BS)

#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& arr){
    int n= arr.size();
    int low=0, high= n-1;
    int mini= INT_MAX;
    int index= -1; //index of mini
    while (low<=high)
    {
        int mid= (low+high)/2;
        //left sorted
        if(arr[low]<=arr[mid]){
            if(arr[low]<mini){
                mini= arr[low];
                index= low;
            }
            low= mid+1;
        }
         //right sorted
        else{
            if(arr[mid]<mini){
                mini= arr[mid];
                index= mid;
            }
            high= mid-1;
        }
    }
    return index;
}
int main()
{
    vector<int> arr = {4, 5, 6, 7, 1, 2, 3};
    int ans = findMin(arr);
    cout << "number of times the array is rotated is : " << ans << "\n";
    return 0;
}
