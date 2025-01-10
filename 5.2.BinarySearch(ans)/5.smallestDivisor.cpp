#include <bits/stdc++.h>
using namespace std;

//Brute
// int divisor(vector<int> &arr, int threshold){
//     int n= arr.size();
//     int maxi= *max_element(arr.begin(), arr.end());
//     for(int d=1; d<=maxi; d++){
//         int sum=0;
//         for(int i=0; i<n; i++){
//             sum += ceil(double(arr[i])/double(d));
//         }
//         if(sum<=threshold) return d;
//     }
//     return -1;
// }
// int main(){
//     vector<int> arr= {1,2,3,4,5};
//     int threshold= 8;
//     int ans= divisor(arr,threshold);
//     cout << "The minimum divisor is: " << ans << "\n";
//     return 0;
// }

//Optimal
int sumByDivisor(vector<int> &arr, int div){
    int n= arr.size();
    int sum= 0;
    for(int i=0;i<n;i++){
        sum += ceil((double)(arr[i]) / (double)(div));
    }
    return sum;
}

int divisor(vector<int> &arr, int threshold){
    int n= arr.size();
    if(n>threshold) return -1;
    int low=1;
    int high= *max_element(arr.begin(), arr.end());
    while(low<=high){
        int mid= (low+high)/2;
        if(sumByDivisor(arr,mid)<=threshold) high= mid-1;
        else low= mid+1;
    }
    return low;
}
int main(){
    vector<int> arr= {1,2,3,4,5};
    int threshold= 8;
    int ans= divisor(arr,threshold);
    cout << "The minimum divisor is: " << ans << "\n";
    return 0;
}