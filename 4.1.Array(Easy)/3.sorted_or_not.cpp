#include <bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        if (arr[i]> arr[i+1])
        {
            return false;
        }
    }
    return true;
}

int main(){

    int arr[]= {2,5,9,11,14};
    int n= 5;
    
    if (isSorted(arr, n)) {
        cout << "is sorted" << endl;
    } else {
        cout << "is unsorted" << endl;
    }
    return 0;
}