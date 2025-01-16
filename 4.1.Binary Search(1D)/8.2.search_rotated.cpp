// Same as problem 8.1 but here the array might have duplicates

#include <bits/stdc++.h>
using namespace std;

// Brute(Linear search)

// Optimal(BS)
bool search_in_rotated(vector<int> &arr, int target){
    int n = arr.size();
    int low= 0, high= n-1;
    while (low<=high)
    {
        int mid= (low+high)/2;

        if(arr[mid]==target) return true;

        if(arr[low]==arr[mid] && arr[mid]==arr[high]){
            low= low+1;
            high= high-1;
            continue;
        }

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
    return false;
}
int main(){
    vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int k = 3;
    bool ans= search_in_rotated(arr,k);
    if (!ans)
        cout << "Target is not present.\n";
    else
        cout << "Target is present in the array" << "\n";
    return 0;
}