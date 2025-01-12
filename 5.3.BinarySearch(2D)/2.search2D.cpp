#include <bits/stdc++.h>
using namespace std;

//brute
// bool searchMatrix(vector<vector<int>>& matrix, int target) {
//     int n = matrix.size(), m = matrix[0].size();
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (matrix[i][j] == target)
//                 return true;
//         }
//     }
//     return false;
// }

//better(check if target is in a certain row then perform bs on it)
// bool binarySearch(vector<int>& nums, int target) {
//     int n = nums.size(); 
//     int low = 0, high = n - 1;
//     while (low <= high) {
//         int mid = (low + high) / 2;
//         if (nums[mid] == target) return true;
//         else if (target > nums[mid]) low = mid + 1;
//         else high = mid - 1;
//     }
//     return false;
// }
// bool searchMatrix(vector<vector<int>>& matrix, int target) {
//     int n = matrix.size();
//     int m = matrix[0].size();
//     for (int i = 0; i < n; i++) {
//         if (matrix[i][0] <= target && target <= matrix[i][m - 1]) {
//             return binarySearch(matrix[i], target);
//         }
//     }
//     return false;
// }

//optimal (hypothetically convert 2D matrix into 1D array and perform a bs on that 1D array)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    int low = 0, high = n * m - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int row = mid / m, col = mid % m;
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}
int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    searchMatrix(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
}

