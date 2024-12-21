#include <bits/stdc++.h>
using namespace std;

//Brute
// bool linearsearch(vector<int>&a, int num){
//     int n= a.size();
//     for(int i=0; i<=n-1; i++){
//         if(a[i]==num){
//             return true;
//         }
//     }
//     return false;
// }
// int longestSuccessiveElements(vector<int>&a){
//     int n= a.size();
//     int longest= 1;
//     for(int i=0; i<=n-1; i++){
//         int x= a[i];
//         int cnt= 1;
//         while(linearsearch(a, x+1)==true){
//             x++;
//             cnt++;
//         }
//         longest= max(longest, cnt);
//     }
//     return longest;
// }

//Better
// int longestSuccessiveElements(vector<int>&a){
//     int n= a.size();
//     if(n==0) return 0;
//     sort(a.begin(), a.end());
//     int last_smaller= INT_MIN;
//     int cnt= 0;
//     int longest= 1;
//     for(int i=0; i<n; i++){
//         if(a[i]-1== last_smaller){
//             cnt++;
//             last_smaller= a[i];
//         }
//         else if(a[i]!=last_smaller){
//             cnt= 1;
//             last_smaller= a[i];
//         }
//         longest= max(longest, cnt);
//     }
//     return longest;
// }

//Optimal
//in optimal put every ele to a set data structure(set only stores unique ele so no redundancy- unordered set)
int longestSuccessiveElements(vector<int>&a){
    int n= a.size();
    if(n==0) return 0;
    int longest= 1;
    unordered_set<int> st;
    for(int i=0; i<n; i++){
        st.insert(a[i]);
    }
    for(auto it:st){
        if(st.find(it-1)==st.end()){ //it is the element we start iterating from to find consec eles after it; but if there exists an element it-1 then iteration is useless. Suppose if we stand at 101 and there exists an ele 100 then we find it-1(here, 101-1) then start finding consec eles from 100(it-1)
            int cnt= 1;
            int x= it;
            while(st.find(x+1)!=st.end()){
                x++;
                cnt++;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}
int main()
{
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans = longestSuccessiveElements(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}