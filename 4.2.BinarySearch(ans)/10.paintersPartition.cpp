//same logic as Book Allocation as well as Split array - Largest Sum problem
// refer to striver a2z dsa sheet for split array largest sum problem


#include <bits/stdc++.h>
using namespace std;

int countPainters(vector<int> &boards, int time) {
    int n = boards.size(); 
    int painters = 1;
    long long boardsPainter = 0;
    for (int i = 0; i < n; i++) {
        if (boardsPainter + boards[i] <= time) {
            boardsPainter += boards[i];
        }
        else {
            painters++;
            boardsPainter = boards[i];
        }
    }
    return painters;
}


//brute
// int findLargestMinDistance(vector<int> &boards, int k) {
//     int low = *max_element(boards.begin(), boards.end());
//     int high = accumulate(boards.begin(), boards.end(), 0);

//     for (int time = low; time <= high; time++) {
//         if (countPainters(boards, time) <= k) {
//             return time;
//         }
//     }
//     return low;
// }

//optimal
int findLargestMinDistance(vector<int> &boards, int k) {
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    while (low <= high) {
        int mid = (low + high) / 2;
        int painters = countPainters(boards, mid);
        if (painters > k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    vector<int> boards = {10, 20, 30, 40};
    int k = 2;
    int ans = findLargestMinDistance(boards, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}


