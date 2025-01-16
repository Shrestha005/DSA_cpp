#include <bits/stdc++.h>
using namespace std;

// //brute force approach
int maxSubarraySum(int arr[], int n){
    int maxi= INT_MIN;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int sum=0;
            for(int k=i; k<=j; k++){
                sum+= arr[k];
            }
            maxi= max(maxi, sum);
        }
    }
    return maxi;
}

//better approach
int maxSubarraySum(int arr[], int n){
    int maxi= INT_MIN;

    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=i; j<n; j++){
            sum+=arr[j];
        maxi= max(maxi, sum);
        }
    }
    return maxi;
}


int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}
