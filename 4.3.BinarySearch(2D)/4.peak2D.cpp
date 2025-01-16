#include<bits/stdc++.h>
using namespace std;

int findMaxIndex(vector<vector<int>> &matrix, int n, int col){
    int maxValue=-1;
    int index=-1;
    for (int i = 0; i < n; i++)
    {
        if(matrix[i][col] > maxValue){
            maxValue= matrix[i][col];
            index= i;
        }
    }
    return index;
}
vector<int> findPeakGrid(vector<vector<int>> &matrix){
    int n= matrix.size();
    int m= matrix[0].size();
    int low= 0, high= m-1;
    while (low<=high)
    {
        int mid= (low+high)/2;
        int maxRowIndex= findMaxIndex(matrix, n, mid);
        int left = mid-1 >= 0 ? matrix[maxRowIndex][mid-1] : -1;
        int right = mid+1 < m ? matrix[maxRowIndex][mid+1] : -1;
        if(matrix[maxRowIndex][mid] > left && matrix[maxRowIndex][mid] > right){
            return {maxRowIndex,mid};
        }
        else if(matrix[maxRowIndex][mid] < left){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return {-1,-1};
}

int main() {
    vector<vector<int>> matrix = {
        {10, 20, 15},
        {21, 30, 14},
        {7, 16, 32}
    };
    vector<int> peak = findPeakGrid(matrix);

    if (peak[0] != -1 && peak[1] != -1) {
        cout << "Peak element found at: (" << peak[0] << ", " << peak[1] << ")" << endl;
        cout << "Peak element value: " << matrix[peak[0]][peak[1]] << endl;
    } else {
        cout << "No peak element found." << endl;
    }

    return 0;
}
