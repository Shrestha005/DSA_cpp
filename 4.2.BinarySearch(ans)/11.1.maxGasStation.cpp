// BRUTE

#include <bits/stdc++.h>
using namespace std;

long double minimizedMaxDistance(vector<int> &arr, int k){
    int n= arr.size();
    vector<int> howMany(n-1,0);
    for(int gasStation=1; gasStation<=k; gasStation++){
        long double maximumSection=-1;
        int maxInd=-1;
        //find section length for every section
        for(int i=0; i<n-1; i++){
            long double diff= (arr[i+1]-arr[i]);
            long double sectionLength= diff / (long double)(howMany[i]+1);
            if(sectionLength>maximumSection){
                maximumSection = sectionLength;
                maxInd = i;
            }
        }
        howMany[maxInd]++;
    }
    //again traverse every section to get the the max of individual section length
    long double maxAns=-1;
    for(int i=0; i<n-1; i++){
        long double diff= (arr[i+1]-arr[i]);
        long double sectionLength= diff / (long double)(howMany[i]+1);   
        maxAns= max(maxAns , sectionLength);
    }
    return maxAns;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    long double ans = minimizedMaxDistance(arr, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}