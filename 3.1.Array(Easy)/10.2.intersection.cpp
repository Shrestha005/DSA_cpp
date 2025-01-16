//optimal (2 pointer approach)

#include <bits/stdc++.h>
using namespace std;

vector<int> findArrayIntersection(vector<int> &A, int n, vector<int> &B, int m) {
    int i = 0;
    int j = 0;
    vector<int> ans;

    while (i < n && j < m) {
        if (A[i] < B[j]) {
            i++;
        } else if (B[j] < A[i]) {
            j++;
        } else {
            ans.push_back(A[i]);
            i++;
            j++;
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

    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
