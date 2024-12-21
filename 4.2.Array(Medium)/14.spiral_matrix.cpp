// only 1 approach : OPTIMAL
// right -> down -> left -> up
//TC: O(m x n)
//SC: O(n)

#include <bits/stdc++.h>

using namespace std;

vector<int> printSpiral(vector<vector<int>> mat) {

  vector<int> ans;

  int n = mat.size(); //rows
  int m = mat[0].size(); //columns 
  int top = 0, left = 0, bottom = n - 1, right = m - 1;

  //all ele traversed
  while (top <= bottom && left <= right) {  
    //left to right
    for (int i = left; i <= right; i++)
      ans.push_back(mat[top][i]);
    top++;
    //top to bottom.
    for (int i = top; i <= bottom; i++)
      ans.push_back(mat[i][right]);
    right--;  
    //right to left.
    if (top <= bottom) {
      for (int i = right; i >= left; i--)
       ans.push_back(mat[bottom][i]);
      bottom--;
    }
    //bottom to top.
    if (left <= right) {
      for (int i = bottom; i >= top; i--)
        ans.push_back(mat[i][left]);
      left++;
    }
  }
  return ans;


}
int main() { 
  vector<vector<int>> mat   {{1, 2, 3, 4},
                             {5, 6, 7, 8},
	                         {9, 10, 11, 12},
		                     {13, 14, 15, 16}};		                     
  vector<int> ans = printSpiral(mat);
  for(int i = 0;i<ans.size();i++){   
    cout<<ans[i]<<" ";
  }
  cout<<endl;
  return 0;
}