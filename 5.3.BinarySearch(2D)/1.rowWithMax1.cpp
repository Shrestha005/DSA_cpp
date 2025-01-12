#include <bits/stdc++.h>
using namespace std;

//brute
// int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
//     int cnt_max = 0;
//     int index = -1;
//     for (int i = 0; i < n; i++) {
//         int cnt_ones = 0;
//         for (int j = 0; j < m; j++) {
//             cnt_ones += matrix[i][j];
//         }
//         if (cnt_ones > cnt_max) {
//             cnt_max = cnt_ones;
//             index = i;
//         }
//     }
//     return index;
// }


//optimal
//lowerbound code to find the first occurence of 1 in matrix
int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}
//n=column
//m=row
int rowWithMaxOnes(vector<vector<int>> &matrix, int n, int m){
    int cntMax=0;
    int index=-1;
    for(int i=0;i<n;i++){
        int countOnes= m - lowerBound(matrix[i], m, 1);
        if(countOnes>cntMax){
            cntMax = countOnes;
            index = i;
        }
    }
    return index;
}
int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    int n = 3, m = 3;
    cout << "The row with maximum no. of 1's is: " <<
         rowWithMaxOnes(matrix, n, m) << '\n';
}