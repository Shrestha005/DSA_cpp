#include <bits/stdc++.h>
using namespace std;

// Brute
// int floorSqrt(int n) {
//     int ans = 0;
//     for (long long i = 1; i <= n; i++) {
//         long long val = i * i;
//         if (val <= n * 1ll) {
//             ans = i;
//         } else {
//             break;
//         }
//     }
//     return ans;
// }




// Optimal 1(uses in built func)
// int floorSqrt(int n) {
//     int ans = sqrt(n);
//     return ans;
// }



// Optimal
int floorSqrt(int n){
    int low= 1;
    int high= n;
    while (low<=high)
    {
        long long mid= (low+high)/2;
        long long val= mid*mid;
        if(val<=(long long)(n)) low= mid+1;
        else high= mid-1;
    }
    return high;
}
int main()
{
    int n = 28;
    int ans = floorSqrt(n);
    cout << "The floor of square root of " << n
         << " is: " << ans << "\n";
    return 0;
}
