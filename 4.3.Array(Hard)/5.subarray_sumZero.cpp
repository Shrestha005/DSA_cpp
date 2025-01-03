#include <bits/stdc++.h>
using namespace std;

//there is only 1 main approach for this problem
int solve(vector<int> &a){
    int maxlen=0;
    int sum=0;
    unordered_map<int, int> sumIndexMap;
    for (int i = 0; i < a.size(); i++)
    {
        sum+=a[i];
        if(sum==0){
            maxlen= i+1;
        }
        else if(sumIndexMap.find(sum) != sumIndexMap.end()){ //if it exists in map
            maxlen= max(maxlen, i-sumIndexMap[sum]);
        }
        else{
            sumIndexMap[sum]= i;
        }
    }
    return maxlen;
}
int main() {
    vector<int> a = {9, -3, 3, -1, 6, -5};
    cout << solve(a) << endl;

    return 0;
}
