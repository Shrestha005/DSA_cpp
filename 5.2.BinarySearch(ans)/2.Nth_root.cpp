#include <bits/stdc++.h>
using namespace std;

// Brute (Hard)

// long long func(int i, int n) {
//     long long ans = 1;
//     for (int j = 1; j <= n; j++) {
//         if (ans > LLONG_MAX / i) { // Check for overflow before multiplication
//             return LLONG_MAX; // Return a large value to indicate overflow
//         }
//         ans *= i; 
//     }
//     return ans;
// }

// int NthRoot(int n, int m){
//     for(int i=1; i<=m; i++){
//         long long val= func(i,n); // this function calculates i ^ n(i power n)
//         if(val==m) return i;
//         else if(val>m) break;
//     }
//     return -1;
// }


// int main()
// {
//     int n = 3, m = 27;
//     int ans = NthRoot(n, m);
//     cout << "The answer is: " << ans << "\n";
//     return 0;
// }


int func(int mid, int n, int m){
    long long ans=1;
    for (int i = 1; i <= n; i++)
    {
        ans= ans*mid;
        if(ans>m) return 2;
    }
    if(ans==m) return 1;
    return 0;
}
int NthRoot(int n, int m){
    int low=1, high=m;
    while(low<=high){
        int mid= (low+high)/2;
        int midN= func(mid,n,m);
        if(midN==1){
            return mid;
        }
        else if(midN==0) low= mid+1;
        else high= mid-1;
    }
    return -1;
}
int main()
{
    int n = 3, m = 27;
    int ans = NthRoot(n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}