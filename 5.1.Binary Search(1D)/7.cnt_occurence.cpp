#include <bits/stdc++.h>
using namespace std;
int firstOccurence(vector<int> arr, int n, int x){
    int low= 0, high= n-1;
    int first= -1;
    while (low<=high)
    {
        int mid= (low+high)/2;
        if(arr[mid]==x){
            first=mid;
            high= mid-1;
        }
        else if(arr[mid]>x) high= mid-1;
        else low= mid+1;
    }
    return first;
}
int lastOccurence(vector<int> arr, int n, int x){
    int low= 0, high= n-1;
    int last= -1;
    while (low<=high)
    {
        int mid= (low+high)/2;
        if(arr[mid]==x){
            last=mid;
            low= mid+1;
        }
        else if(arr[mid]>x) high= mid-1;
        else low= mid+1;
    }
    return last;
}
pair<int,int> firstAndLastOccurence(vector<int> &arr, int n, int k){
    int first= firstOccurence(arr, n, k);
    if(first==-1) return {-1,-1};
    int last= lastOccurence(arr, n, k);
    return {first,last};
}
int count(vector<int> &arr, int n, int x){
    pair<int,int> ans= firstAndLastOccurence(arr, n, x);
    if(ans.first==-1) return 0;
    return (ans.second-ans.first+1);
}
int main() {
    vector<int> a = {3, 4, 13, 13, 13, 20, 40};
    int n = 7;
    int target = 13;
    int result = count(a, n, target);
    cout << "Count Of Occurrence: " << result << "\n";
    return 0;
}