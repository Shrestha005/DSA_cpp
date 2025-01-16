#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    void recurPermute(int index, vector<int> &nums, vector<vector<int>> &ans) {
        // Base case: if index reaches the size of the array, store the permutation
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }
        // Loop through the array and swap elements
        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);             // Swap current element with the 'index'
            recurPermute(index + 1, nums, ans);     // Recur for the next index
            swap(nums[index], nums[i]);             // Backtrack to restore the original state
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> ans;                   // Vector to store all permutations
        recurPermute(0, nums, ans);                // Call the helper function
        return ans;                                // Return the result
    }
};

int main() {
    Solution solution;
    vector<int> nums;
    int n, input;

    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> input;
        nums.push_back(input);
    }

    vector<vector<int>> result = solution.permute(nums);

    cout << "All permutations of the array are:\n";
    for (const auto &permutation : result) {
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
