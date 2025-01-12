// BETTER(PRIORITY QUEUE) - enough for interviews

#include <bits/stdc++.h>
using namespace std;

long double minimizedMaxDistance(vector<int> &arr, int k){
    int n= arr.size();
    vector<int> howMany(n-1,0);
    priority_queue<pair<long double,int>> pq;
    for(int i=0; i<n-1; i++){
        pq.push({arr[i+1]-arr[i] , i});
    }
    for(int gasStation=1; gasStation<=k; gasStation++){
        auto tp= pq.top();
        pq.pop();
        int sectionIndex= tp.second;
        howMany[sectionIndex]++; 

        long double initialDiff= arr[sectionIndex+1]-arr[sectionIndex];
        long double NewSectionLen= initialDiff / (long double) (howMany[sectionIndex]+1);
        pq.push({NewSectionLen,sectionIndex});
    }
    return pq.top().first;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    long double ans = minimizedMaxDistance(arr, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
