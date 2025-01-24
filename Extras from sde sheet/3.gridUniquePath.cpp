#include<bits/stdc++.h>
using namespace std;

//brute = tc and sc are exponential
// int countPath(int i, int j, int n, int m){ //starting point
//     if(i==(n-1) && j==(m-1)) return 1;
//     if(i>=n || j>=m) return 0;
//     else return countPath(i+1, j, n, m) + countPath(i, j+1, n, m);
// }
// int uniquePaths(int m, int n) {
//     return countPath(0,0,m,n);
// }
// int main()
// {
//     int totalCount= uniquePaths(3,7);
//     cout<<"The total number of Unique Paths are "<<totalCount<<endl;
// }


//better = tc and sc are O(n*m)
// int countPath(int i, int j, int n, int m, vector<vector<int>> &dp){
//     if(i==(n-1) && j==(m-1)) return 1;
//     if(i>=n || j>=m) return 0;
//     if(dp[i][j] != -1) return dp[i][j];
//     else return dp[i][j]= countPath(i+1,j,n,m,dp) + countPath(i,j+1,n,m,dp);
// }
// int uniquePaths(int n, int m){
//     vector<vector<int>> dp(n , vector<int>(m,-1));
//     int num= countPath(0,0,n,m,dp);
//     if(n==1 && m==1) return num;
//     return dp[0][0];
// }
// int main()
// {
//     int totalCount= uniquePaths(3,7);
//     cout<<"The total number of Unique Paths are "<<totalCount<<endl;
// }


//optimal = tc is O(n-1) or O(m-1) and sc is O(1)
//NCr formula
int uniquePath(int m, int n){
    int N= n+m-2;
    int r= m-1;
    double result= 1;
    for (int i = 1; i <= r; i++)
    {
        result= result * (N-r+i)/i;
        return (int)result;
    }
}
int main()
{
    int totalCount= uniquePath(2,3);
    cout<<"The total number of Unique Paths are "<<totalCount<<endl;
}