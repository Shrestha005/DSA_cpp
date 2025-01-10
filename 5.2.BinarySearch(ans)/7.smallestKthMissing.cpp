#include<bits/stdc++.h>
using namespace std;

// int missing(vector<int> &arr, int k){
//     int n= arr.size();
//     for(int i=0; i<n; i++){
//         if(arr[i]<=k) k++;
//         else break;
//     }
//     return k;
// }
// int main()
// {
//     vector<int> a = {4, 7, 9, 10};
//     int k = 4;
//     int ans = missing(a, k);
//     cout << "The missing number is: " << ans << "\n";
//     return 0;
// }

int missing(vector<int> &arr, int k){
    int n= arr.size();
    int low=0, high= (n-1);
    while(low<=high){
        int mid= (low+high)/2;
        int missing= arr[mid] - (mid+1);
        if(missing < k) low=mid+1;
        else high=mid-1; 
    } 
    //return arr[high]+more
    //more= (k-missing)
    //missing= arr[high]-(high+1)
    //so, more= k- arr[high]+high+1
    //arr[high]+more = arr[high]+k- arr[high]+high+1
    //               = k+high+1
    return high+k+1;
    //low= high+1 //so we can return low+k as well
}
int main()
{
    vector<int> a = {4, 7, 9, 10};
    int k = 4;
    int ans = missing(a, k);
    cout << "The missing number is: " << ans << "\n";
    return 0;
}
