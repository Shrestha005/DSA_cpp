#include <bits/stdc++.h>
using namespace std;
// Brute
// Step 1: whenever we get a 0 we turn the rest column and row elements of the 0 into -1 we continue the process for the rest of the 0 present in the initial matrix 
// Step 2: we turn all the -1 into 0. then return matrix.
// TC: O((N*M)*(N + M)) + O(N*M)
// void markRow(vector<vector<int>> &matrix, int n, int m, int i) {
//     // set all non-zero elements as -1 in the row i:
//     for (int j = 0; j < m; j++) {
//         if (matrix[i][j] != 0) {
//             matrix[i][j] = -1;
//         }
//     }
// }
// void markCol(vector<vector<int>> &matrix, int n, int m, int j) {
//     // set all non-zero elements as -1 in the col j:
//     for (int i = 0; i < n; i++) {
//         if (matrix[i][j] != 0) {
//             matrix[i][j] = -1;
//         }
//     }
// }
// vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
//     // Set -1 for rows and cols
//     // that contains 0. Don't mark any 0 as -1:
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (matrix[i][j] == 0) {
//                 markRow(matrix, n, m, i);
//                 markCol(matrix, n, m, j);
//             }
//         }
//     }
//     // Finally, mark all -1 as 0:
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (matrix[i][j] == -1) {
//                 matrix[i][j] = 0;
//             }
//         }
//     }
//     return matrix;
// }

// Better
// Step 1: create a row and column array mark the index of the zero present in row and column array.
// Step 2: then after finding all the 0
// Step 3: together turn the row and column ele to 0, condition is => [if (row[i] || col[j]) {matrix[i][j] = 0;]
// TC: O(2*(N*M))
// vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
//     int row[n] = {0}; // row array
//     int col[m] = {0}; // col array
//     // Traverse the matrix:
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (matrix[i][j] == 0) {
//                 // mark ith index of row wih 1:
//                 row[i] = 1;
//                 // mark jth index of col wih 1:
//                 col[j] = 1;
//             }
//         }
//     }
//     // Finally, mark all (i, j) as 0
//     // if row[i] or col[j] is marked with 1.
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (row[i] || col[j]) {
//                 matrix[i][j] = 0;
//             }
//         }
//     }
//     return matrix;
// }

//Optimal









int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = zeroMatrix(matrix, n, m);
    cout << "The Final matrix is: \n";
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}

