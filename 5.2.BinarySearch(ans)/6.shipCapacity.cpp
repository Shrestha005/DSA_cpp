#include <bits/stdc++.h>
using namespace std;

int daysReqd(vector<int> &weight, int capacity){
    int n= weight.size();
    int day=1, load=0;
    for(int i=0; i<n; i++){
        load += weight[i];
        if(load>capacity){
            day++;
            load= weight[i];
        }
    }
    return day;
}

//brute
// int capacity(vector<int> &weight, int d){
//     int maxi= *max_element(weight.begin(), weight.end());
//     int sum = accumulate(weight.begin(), weight.end(), 0);
//     for(int i= maxi; i<=sum; i++){
//         if(daysReqd(weight,i) <= d) return i;
//     }
//     return -1;
// }

//optimal
int capacity(vector<int> &weight, int d){
    int low= *max_element(weight.begin(), weight.end());
    int high = accumulate(weight.begin(), weight.end(), 0);
    while(low<=high){
        int mid= (low+high)/2;
        int numberOfDays= daysReqd(weight,mid);
            if(numberOfDays<=d) high=mid-1;
            else low=mid+1;
    }
    return low;
}


int main()
{
    vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
    int d = 5;
    int ans = capacity(weights, d);
    cout << "The minimum capacity should be: " << ans << "\n";
    return 0;
}
