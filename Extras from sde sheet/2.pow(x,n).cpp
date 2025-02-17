#include<bits/stdc++.h>
using namespace std;

//brute = tc is O(n)
// double myPow(double x, int n){
//     double ans= 1.0;
//     for (int i = 0; i < n; i++)
//     {
//         ans= ans*x;
//     }
//     return ans;    
// }
// int main()
// {
//     cout<<myPow(2,10)<<endl;
// }

//optimal = tc is O(logn)

double myPow(double x, int n){
    double ans= 1.0;
    long long nn= n;
    if(nn<0) nn=-1*nn;
    while(nn>0){
        if(nn%2==1){
            ans=ans*x;
            nn=nn-1;
        }
        else{
            x=x*x;
            nn=nn/2;
        }
    }   
    if(n<0) ans= 1.0/ans;
    return ans;
}
int main()
{
    cout<<myPow(2,10)<<endl;
}