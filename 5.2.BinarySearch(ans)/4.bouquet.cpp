#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int> &arr, int day, int m, int k){
    int n= arr.size();
    int cnt=0, numOfBouquet=0;
    for(int i=0; i<n; i++){
        if(day>=arr[i]){
            cnt++;
        }
        else{
            numOfBouquet += (cnt/k);
            cnt=0;
        }
    }
    numOfBouquet += (cnt/k);
    return numOfBouquet >= m;
}


//rosegarden function searches min possible from all the possible answers

//brute
// int roseGarden(vector<int> &arr, int m, int k){
//     //total number of flowers m*k
//     int val= m * 1ll * k * 1ll;
//     int n= arr.size();
//     if(val>n) return -1; //impossible case(as minimum number of flowers cannot exceed total number of flowers)
//     //find max , min
//     int mini= INT_MAX, maxi= INT_MIN;
//     for(int i=0; i<n; i++){
//         mini= min(mini, arr[i]);
//         maxi= max(maxi, arr[i]);
//     }
//     for(int i=mini; i<=maxi; i++){
//         if(possible(arr,i,m,k)==true) return i;
//     }
//     return -1;
// }

//optimal
int roseGarden(vector<int> &arr, int m, int k){
    //total number of flowers m*k
    int val= m * 1ll * k * 1ll;
    int n= arr.size();
    if(val>n) return -1; //impossible case(as minimum number of flowers cannot exceed total number of flowers)
    //find max , min
    int mini= INT_MAX, maxi= INT_MIN;
    for(int i=0; i<n; i++){
        mini= min(mini, arr[i]);
        maxi= max(maxi, arr[i]);
    }
    int low= mini, high= maxi;
    while(low<=high){
        int mid= (low+high)/2;
        if(possible(arr, mid, m, k)==true) high=mid-1;
        else low=mid+1;
    }
    return low;
}


int main()
{
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int k = 3;
    int m = 2;
    int ans = roseGarden(arr, k, m);
    if (ans == -1)
        cout << "We cannot make m bouquets.\n";
    else
        cout << "We can make bouquets on day " << ans << "\n";
    return 0;
}


