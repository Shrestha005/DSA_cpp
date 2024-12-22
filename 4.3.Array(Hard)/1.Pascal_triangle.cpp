// Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.

// Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.

// Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle.

#include <bits/stdc++.h>
using namespace std;

// Variation 1 (optimal)
// int nCr(int n, int r){
//     long long res=1;
//     //nCr
//     for (int i = 0; i < r; i++)
//     {
//         res= res*(n-i);
//         res= res/(i+1);
//     }
//     return res;
// }
// int pascalTriangle(int r, int c){
//     int element= nCr(r-1, c-1);
//     return element;
// }
// int main()
// {
//     int r = 5; // row 
//     int c = 3; // col 
//     int element = pascalTriangle(r, c);
//     cout << "The element at position (r,c) is: "<< element << "\n";
//     return 0;
// }

// Variation 2 (brute)
// int nCr(int n, int r) {
//     long long res = 1;
//     // nCr
//     for (int i = 0; i < r; i++) {
//         res = res * (n - i);
//         res = res / (i + 1);
//     }
//     return res;
// }
// void pascalTriangle(int n){
//     for (int c = 1; c <= n; c++) //printing row for each col number
//     {
//         cout<< nCr(n-1, c-1)<< " ";
//     }
//     cout<< "\n";
// }
// int main()
// {
//     int n = 5;
//     pascalTriangle(n);
//     return 0;
// }

// Variation 2 (optimal)
// void pascalTriangle(int n){
//     long long ans= 1;
//     cout<< ans<< " "; //first ele
//     //rest ele
//     for (int i = 1; i < n; i++)
//     {
//         ans= ans* (n-i);
//         ans= ans/ i;
//         cout<< ans<< " ";
//     }
//     cout<< endl;
// }
// int main()
// {
//     int n = 5;
//     pascalTriangle(n);
//     return 0;
// }

// Variation 3 (brute)
// int nCr(int n, int r) {
//     long long res = 1;
//     // nCr
//     for (int i = 0; i < r; i++) {
//         res = res * (n - i);
//         res = res / (i + 1);
//     }
//     return (int)(res);
// }
// vector<vector<int>> pascalTriangle(int n) {
//     vector<vector<int>> ans;
//     //Store entire triangle:
//     for (int row = 1; row <= n; row++) {
//         vector<int> tempLst; // temp list
//         for (int col = 1; col <= row; col++) {
//             tempLst.push_back(nCr(row - 1, col - 1));
//         }
//         ans.push_back(tempLst);
//     }
//     return ans;
// }
// int main()
// {
//     int n = 5;
//     vector<vector<int>> ans = pascalTriangle(n);
//     for (auto it : ans) {
//         for (auto ele : it) {
//             cout << ele << " ";
//         }
//         cout << "\n";
//     }
//     return 0;
// }

// Variation 3 (optimal)
vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1); //1st ele
    //rest ele
    for (int col = 1; col < row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}
vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;
    //store entire triangle
    for (int row = 1; row <= n; row++) {
        ans.push_back(generateRow(row));
    }
    return ans;
}
int main()
{
    int n = 5;
    vector<vector<int>> ans = pascalTriangle(n);
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}






