#include <bits/stdc++.h>
using namespace std;

// brute
// vector<vector<int>> quartet(vector<int> &arr, int target){
//     int n = arr.size();
//     set<vector<int>> st;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i+1; j < n; j++)
//         {
//             for (int k = j+1; k < n; k++)
//             {
//                 for (int l = k+1; l < n; l++)
//                 {
//                     long long sum= arr[i]+ arr[j];
//                     sum+=arr[k];
//                     sum+=arr[l];
//                     if(sum==target){
//                         vector<int> temp= {arr[i], arr[j], arr[k], arr[l]};
//                         sort(temp.begin(), temp.end());
//                         st.insert(temp);
//                     }
//                 }   
//             } 
//         }  
//     }  
//     vector<vector<int>> ans(st.begin(), st.end());
//     return ans;
// }
// int main()
// {
//     vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
//     int target = 9;
//     vector<vector<int>> ans = quartet(nums, target);
//     cout << "The quadruplets are: \n";
//     for (auto it : ans) {
//         cout << "[";
//         for (auto ele : it) {
//             cout << ele << " ";
//         }
//         cout << "] ";
//     }
//     cout << "\n";
//     return 0;
// }

// better
// vector<vector<int>> quartet(vector<int> &arr, int target){
//     int n= arr.size();
//     set<vector<int>> st;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i+1; j < n; j++)
//         {
//             set<long long> hashset;
//             for (int k = j+1; k < n; k++)
//             {
//                 long long sum= arr[i]+ arr[j];
//                 sum+= arr[k];
//                 long long fourth= target- sum;
//                 if(hashset.find(fourth)!= hashset.end()){
//                     vector<int> temp= {arr[i], arr[j], arr[k], (int)(fourth)};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//                 }
//                 hashset.insert(arr[k]);
//             }   
//         } 
//     }
//     vector<vector<int>> ans(st.begin(), st.end());
//     return ans;
// }
// int main()
// {
//     vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
//     int target = 9;
//     vector<vector<int>> ans = quartet(nums, target);
//     cout << "The quadruplets are: \n";
//     for (auto it : ans) {
//         cout << "[";
//         for (auto ele : it) {
//             cout << ele << " ";
//         }
//         cout << "] ";
//     }
//     cout << "\n";
//     return 0;
// }

// optimal
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> quartet(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        if(i>0 && arr[i]==arr[i-1]) continue; //to avoid duplicates
        for (int j = i+1; j < n; j++)
        {
            if(j>i+1 && arr[j]==arr[j-1]) continue; //to avoid duplicates
            //2 ptrs
            int k= j+1;
            int l= n-1;
            while (k<l)
            {
                long long sum= arr[i];
                sum+=arr[j];
                sum+=arr[k];
                sum+=arr[l];
                if(sum==target){
                    vector<int> temp= {arr[i], arr[j], arr[k], arr[l]};
                    ans.push_back(temp);
                    k++, l--;
                    //to avoid duplicates
                    while(k<l && arr[k]==arr[k-1]) k++;
                    while(k<l && arr[l]==arr[l-1]) l++;
                }
                else if(sum< target) k++;
                else l--;
            }
        }
    }
   return ans; 
}
int main()
{
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    vector<vector<int>> ans = quartet(nums, target);
    cout << "The quadruplets are: \n";
    for (auto it : ans) {
        cout << "[";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}

