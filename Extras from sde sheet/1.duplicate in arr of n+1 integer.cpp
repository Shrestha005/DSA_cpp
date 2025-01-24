#include<bits/stdc++.h>
using namespace std;

//brute
//sort the array and find duplicate
//tc is O(nlogn + n)
// int duplicate(vector<int> &arr){
//     int n= arr.size();
//     sort(arr.begin(),arr.end());
//     for (int i = 0; i < n; i++)
//     {
//         if(arr[i]==arr[i+1]) return arr[i];
//     } 
// }
// int main(){
//     vector<int> arr;
//  arr = {2,1,6,5,3,4,7,5};
//     cout << "The duplicate element is " << duplicate(arr) << endl;
// }

//better
//take a frequency array and storethe frequency of the arr elements in the frequency arr in its corresponding index
//tc is O(n)
// int duplicate(vector<int> &arr){
//     int n= arr.size();
//     int freq[n+1]={0};
//     for (int i = 0; i < n; i++)
//     {
//         if(freq[arr[i]]==0) freq[arr[i]]+=1;
//         else return arr[i];
//     }
//     return 0;
// }
// int main(){
//     vector<int> arr;
//  arr = {2,1,6,5,3,4,7,5};
//     cout << "The duplicate element is " << duplicate(arr) << endl;
// }

//optimal
//linked list cycle method
//tc is O(n)
int duplicate(vector<int> arr){
    int slow= arr[0];
    int fast= arr[0];
    do
    {
        slow= arr[slow];
        fast= arr[arr[fast]];
    } while (slow!=fast);
    fast= arr[0];
    while (slow!=fast)
    {
        slow= arr[slow];
        fast= arr[fast];
    }
    return slow;
}
int main() {
  vector < int > arr;
  arr = {2,1,6,5,3,4,7,5};
  cout << "The duplicate element is " << duplicate(arr) << endl;
}