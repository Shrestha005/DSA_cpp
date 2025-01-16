#include <bits/stdc++.h>
using namespace std;

// HARD!

// BRUTE+OPTIMAL 

// findMax and calculateTotalHours are same for brute and optimal solutions
int findMax(vector<int> &v){
    int maxi= INT_MIN;
    int n= v.size();
    for(int i=0; i<n; i++){
        maxi= max(maxi, v[i]);
    }
    return maxi;
}
int calculateTotalHours(vector<int> &v, int hourly){
    int totalHour= 0;
    int n= v.size();
    for(int i=0; i<n; i++){
        totalHour+= ceil((double)(v[i]) / (double)(hourly));
    }
    return totalHour;
}

// function of brute
// int bananasToEatPerHour(vector<int> &v, int h){
//     int maxi= findMax(v);
//     for(int i=1; i<=maxi; i++){
//         int reqTime= calculateTotalHours(v,i);
//         if(reqTime<=h) return i;
//     }
//     return maxi;
// }

// function of optimal
int bananasToEatPerHour(vector<int> &v, int h){
    int low= 1, high= findMax(v);
    while (low<=high)
    {
        int mid= (low+high)/2;
        int reqTime= calculateTotalHours(v, h);
        if(reqTime<=mid) high= mid-1;
        else low= mid+1;
    }
    return low;
}


int main()
{
    vector<int> v = {7, 15, 6, 3};
    int h = 8;
    int ans = bananasToEatPerHour(v, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
    return 0;
}
