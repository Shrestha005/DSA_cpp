#include<bits/stdc++.h>
using namespace std;

//Brute

// vector<int> printLeadersBruteForce(int arr[], int n) {
//   vector<int> ans; 
//   for (int i = 0; i < n; i++) {
//     bool leader = true;
//     //Checking whether arr[i] is greater than all 
//     //the elements in its right side
//     for (int j = i + 1; j < n; j++)
//       if (arr[j] > arr[i]) {         
//         // If any element found is greater than current leader
//         // curr element is not the leader.
//         leader = false;
//         break;
//       }
//     // Push all the leaders in ans array.
//     if (leader)
//     ans.push_back(arr[i]);
//   } 
//   return ans;
// }

//Optimal

vector<int> leader(vector<int>&a){
    vector<int> ans;
    int maxi= INT_MIN;
    int n= a.size();
    for(int i=n-1; i>=0; i--){
        if(a[i]>maxi){
            ans.push_back(a[i]);
            maxi= a[i];
        }
    }
    //sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    return ans;
}
int main() {  
  // Array Initialization.
    vector<int> a = {10, 22, 12, 3, 0, 6};
    vector<int> ans = leader(a); 
    for(int i=0; i<ans.size(); i++){    
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
