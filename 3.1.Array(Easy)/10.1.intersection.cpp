//brute

#include <bits/stdc++.h>
using namespace std;

vector<int> findArrayIntersection(vector<int> &A, int n, vector<int> &B, int m) {
    vector<int> ans;
    int vis[m] = {0}; // Tracks elements in B that have been used in the intersection

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(A[i] == B[j] && vis[j] == 0) {
                ans.push_back(A[i]);
                vis[j] = 1;
                break;
            }
            if(B[j] > A[i]) break; // Assuming both arrays are sorted
        }
    }
    
    return ans;
}

int main() {
    vector<int> A = {1, 2, 2, 3, 4};
    vector<int> B = {2, 2, 3, 3, 5};
    int n = A.size();
    int m = B.size();
    
    vector<int> result = findArrayIntersection(A, n, B, m);

    for(int num : result) {
        cout << num << " ";
    }

    return 0;
}
