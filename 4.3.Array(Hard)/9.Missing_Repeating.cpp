#include <bits/stdc++.h>
using namespace std;

// Brute
// vector<int> findMissingRepeatingNumbers(vector<int> a) {
//     int n = a.size(); // size of the array
//     int repeating = -1, missing = -1;
//     for (int i = 1; i <= n; i++) {
//         int cnt = 0;
//         for (int j = 0; j < n; j++) {
//             if (a[j] == i) cnt++;
//         }
//         if (cnt >1) repeating = i;
//         else if (cnt == 0) missing = i;
//         if (repeating != -1 && missing != -1)
//             break;
//     }
//     return {repeating, missing};
// }
// int main()
// {
//     vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
//     vector<int> ans = findMissingRepeatingNumbers(a);
//     cout << "The repeating and missing numbers are: {"
//          << ans[0] << ", " << ans[1] << "}\n";
//     return 0;
// }

// Better
// vector<int> findMissingRepeatingNumbers(vector<int> a){
//     int n= a.size();
//     int hash[n+1]={0};
//     for(int i=0; i<n; i++){
//         hash[a[i]]++;
//     }
//     int repeating= -1, missing= -1;
//     for(int i=1; i<=n; i++){
//         if(hash[i]>1) repeating= i;
//         else if(hash[i]==0) missing= i;
//         if(repeating!=-1 && missing!=-1) break;
//     }
//     return{repeating, missing};
// }
// int main()
// {
//     vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
//     vector<int> ans = findMissingRepeatingNumbers(a);
//     cout << "The repeating and missing numbers are: {"
//          << ans[0] << ", " << ans[1] << "}\n";
//     return 0;
// }

// Optimal 1(Maths) (enough for interview)
// Method:
// find S-SN(i.e. x-y) and S2-S2N(i.e. x^2-y^2)
// then we find S+SN(i.e. x+y)
// finally calculate x and y (x=repeating, y=missing)
vector<int> findMissingRepeatingNumbers(vector<int> a){
    long long n= a.size();
    //two arrays has to be considered: one is the correct version of array that should be it, second is the one given with repeating and missing numbers
    //sum and sum of square of correct array
    long long SN= (n*(n+1))/2;
    long long S2N= (n*(n+1)*(2*n+1))/6;
    //sum and sum of square of given array with repeating and missing numbers
    long long S=0, S2=0;
    for(int i=0; i<n; i++){
        S+=a[i];
        S2+= (long long) a[i] * (long long) a[i];
    }
    long long val1= S-SN; //x-y
    long long val2= S2-S2N; //x^2-y^2
    val2= val2/val1; //x+y
    long long x= (val1+val2)/2; //[(x-y)+(x+y)]/2 = x
    long long y= (val2-x); // [(x+y)-x] = y
    return {(int)x, (int)y};
}
int main()
{
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}

// Optimal 2(XOR) (hard so no need to explain in interview)
// study from striver array(hard)
