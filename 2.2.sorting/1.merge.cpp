#include<bits/stdc++.h>
using namespace std;         

void merge(vector<int> &arr, int lo, int mid, int hi){
    vector<int> temp;
    int left= lo;
    int right= mid+1;
    while (left<= mid && right<= hi)
    {
        if (arr[left]<=arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }  
    }
    while (left<=mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right<=hi)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = lo; i <= hi; i++)
    {
        arr[i]= temp[i-lo];
    } 
}
void mergeSort(vector<int> &arr, int lo, int hi){
    if(lo== hi) return;
    int mid= (lo+ hi)/2;
    mergeSort(arr, lo, mid);
    mergeSort(arr, mid+1, hi);
    merge(arr, lo, mid, hi);
}


int main() {

    vector<int> arr = {9, 4, 7, 6, 3, 1, 5}  ;
    int n = 7;

    cout << "Before Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;
    mergeSort(arr, 0, n - 1);
    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;
    return 0 ;
}