#include<bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int> &stalls , int dist, int cows){
    int n= stalls .size();
    int cntCows=1, last= stalls [0];
    for(int i=1; i<n; i++){
        if((stalls [i]-last)>=dist){
            cntCows++;
            last=stalls[i];
        }
        if(cntCows>=cows) return true;
    }
    return false;
}

//Brute
// int distance(vector<int> &stalls , int k){
//     int n= stalls.size();
//     sort(stalls.begin(), stalls .end());
//     int maxPossibleDistance = stalls[n-1]-stalls[0];
//     for(int i= stalls[0]; i<= maxPossibleDistance; i++){
//         if(canWePlace(stalls,i,k)==true) continue;
//         return (i-1);
//     }
//     return maxPossibleDistance;
// }


//optimal
int distance(vector<int> &stalls , int k){
    int n= stalls.size();
    sort(stalls.begin(), stalls .end());
    int low=stalls[0] , high=stalls[n-1]-stalls[0];
    while (low<=high)
    {
        int mid= (low+high)/2;
        if(canWePlace(stalls,mid,k)==true) low=mid+1;
        else high=mid-1;
    }
    return high;
}


int main()
{
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    int ans = distance(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    return 0;
}