#include <bits/stdc++.h>
using namespace std;

// Brute(linear search)

// Optimal(BS)
// step 1- identify the sorted half 
// step 2- check if element is present in sorted half or not 
// step 3- if present eliminate the other half and search in other half

int search_in_rotated(vector<int> &arr, int n, int target){
    int low= 0, high= n-1;
    while (low<=high)
    {
        int mid= (low+high)/2;
        if(arr[mid]==target) return mid;
        //left sorted
        else if(arr[low]<=arr[mid]){
            //present in left 
            if(arr[low]<=target && target<=arr[mid]) high=mid-1;
            //not present in left
            else low=mid+1;
        }
        //right sorted
        else{
            //present in right 
            if(arr[mid]<=target && target<=arr[high]) low= mid+1;
            //not present in right 
            else high=mid-1;
        }
    }
    return -1;
}
int main(){
    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int n = 9, k = 1;
    int ans= search_in_rotated(arr,n,k);
    if (ans == -1)
        cout << "Target is not present.\n";
    else
        cout << "The index is: " << ans << "\n";
    return 0;
}