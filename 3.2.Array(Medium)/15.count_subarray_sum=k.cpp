#include <bits/stdc++.h>
using namespace std;  

//Brute
// int findAllSubarraysWithGivenSum(vector<int> &arr, int k){
//     int n = arr.size();
//     int cnt = 0; 
//     for (int i = 0 ; i < n; i++) { 
//         for (int j = i; j < n; j++) { 
//             int sum = 0;
//             for (int K = i; K <= j; K++) // Fixed K to k in the loop for consistency
//                 sum += arr[K]; // Fixed K to k here as well
//             //sum value given is lowercase k so we take loop with K(uppercase)
//             if (sum == k)
//                 cnt++;
//         }
//     }
//     return cnt;
// }
// int main()
// {
//     vector<int> arr = {3, 1, 2, 4}; // Added <int> for proper vector declaration
//     int k = 6;
//     int cnt = findAllSubarraysWithGivenSum(arr, k);
//     cout << "The number of subarrays is: " << cnt << "\n";
//     return 0;
// }

//Better
// int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
//     int n = arr.size(); 
//     int cnt = 0; 
//     for (int i = 0 ; i < n; i++) { 
//         int sum = 0;
//         for (int j = i; j < n; j++) {
//             sum += arr[j];
//             if (sum == k)
//                 cnt++;
//         }
//     }
//     return cnt;
// }
// int main()
// {
//     vector<int> arr = {3, 1, 2, 4};
//     int k = 6;
//     int cnt = findAllSubarraysWithGivenSum(arr, k);
//     cout << "The number of subarrays is: " << cnt << "\n";
//     return 0;
// }

//Optimal
// To count subarrays with sum 𝐾, use a running prefix sum S and a hashmap to track occurrences of S−K, adding their counts to the result.
int findAllSubarraysWithGivenSum(vector < int > & arr, int k){
    int n= arr.size();
    map<int, int> mpp;
    int preSum=0, cnt=0;
    mpp[0]= 1; //set 0 in map;  key:value
    for (int i = 0; i < n; i++)
    {
        preSum+=arr[i];
        int remove= preSum-k;
        cnt+=mpp[remove];
        mpp[preSum]+=1;
    }
    return cnt;
}
int main()
{
    vector<int> arr = {3, 1, 2, 4};
    int k = 6;
    int cnt = findAllSubarraysWithGivenSum(arr, k);
    cout << "The number of subarrays is: " << cnt << "\n";
    return 0;
}