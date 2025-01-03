#include <bits/stdc++.h>
using namespace std;

//Brute
// int findAllSubarraysWithGivenXOR(vector<int> &arr, int targetXOR){
//     int n = arr.size();
//     int cnt = 0; 
//     for (int i = 0 ; i < n; i++) { 
//         for (int j = i; j < n; j++) { 
//             int xorr = 0;
//             for (int k = i; k <= j; k++) {
//                 xorr = xorr ^ arr[k]; 
//             }
//             if (xorr == targetXOR) cnt++;
//         }
//     }
//     return cnt;
// }
// int main()
// {
//     vector<int> arr = {4, 2, 2, 6, 4};
//     int k = 6;
//     int cnt = findAllSubarraysWithGivenXOR(arr, k);
//     cout << "The number of subarrays with XOR k is: " << cnt << "\n";
//     return 0;
// }

//Better
// int findAllSubarraysWithGivenXOR(vector<int> &arr, int targetXOR){
//     int n = arr.size();
//     int cnt = 0; 
//     for (int i = 0 ; i < n; i++) { 
//         int xorr = 0;
//         for (int j = i; j < n; j++) { 
//                 xorr = xorr ^ arr[j]; 
//                 if (xorr == targetXOR) cnt++;
//             }
//         }
//     return cnt;
// }
// int main()
// {
//     vector<int> arr = {4, 2, 2, 6, 4};
//     int k = 6;
//     int cnt = findAllSubarraysWithGivenXOR(arr, k);
//     cout << "The number of subarrays with XOR k is: " << cnt << "\n";
//     return 0;
// }

//Optimal
int findAllSubarraysWithGivenXOR(vector <int> &arr, int targetXOR){
    int n= arr.size();
    int xr= 0;
    map<int, int> mpp;
    mpp[xr]++; //set 0 in map;  key:value
    int cnt= 0;
    for (int i = 0; i < n; i++)
    {
        xr= xr ^ arr[i]; //prefix xor
        int x= xr ^ targetXOR; //x= xr^k
        cnt+=mpp[x]; //add count of xr^k
        mpp[xr]++;
    }
    return cnt;
}
int main()
{
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;
    int cnt = findAllSubarraysWithGivenXOR(arr, k);
    cout << "The number of subarrays with XOR k is: " << cnt << "\n";
    return 0;
}