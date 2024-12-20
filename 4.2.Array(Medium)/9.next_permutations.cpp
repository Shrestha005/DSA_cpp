// Brute : i.generate all permutations sorted
//         ii.linear search
//         iii.next index is the next permutation

//Better : Use stl
//         std::prev_permutataion(first, last)
//         std::next_permutation(first, last);

//Optimal : i. find longest prefix matches arr[i]<arr[i+1]
//          ii. find no. greater than i but lesser than the rest
//          iii. then arrange all the rest nos. in sorted order

//Better
// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// int main() {
//     int arr[] = {1,3,2}; 
//     next_permutation(arr,arr+3);//using in-built function of C++ 
//     cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]; 
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterPermutation(vector<int> &A){
    int n = A.size(); 
    // Step 1: Find breakpoint (ind) and the longest prefix
    int ind = -1;
    for (int i = n - 2; i >= 0; i--) {
        if (A[i] < A[i + 1]) {
            ind = i;
            break;
        }
    }
    if (ind == -1) { // In case no breakpoint, the sequence is the largest permutation
        reverse(A.begin(), A.end());
        return A;
    }
    // Step 2: Find the next greater element to A[ind], then swap them
    for (int i = n - 1; i > ind; i--) {
        if (A[i] > A[ind]) {
            swap(A[i], A[ind]);
            break;
        }
    }
    // Step 3: Reverse the suffix after ind to get the next permutation
    reverse(A.begin() + ind + 1, A.end());    
    return A;
}

int main() {
    vector<int> A = {2, 1, 5, 4, 3, 0, 0};  // Input vector
    vector<int> ans = nextGreaterPermutation(A);
    cout << "The next permutation is: ";
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
