#include <bits/stdc++.h> 
using namespace std;

void printArray(int ans[] , int n){
    cout << "The reversed array is : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}

void reverseArray(int arr[] , int n){
    int ans[n];
    for (int i = n-1; i >= 0; i--)
    {
        ans[n-i-1] = arr[i];
    }
    printArray(ans , n);    
}
int main(){
    int n = 5;
    int arr[] = {1,2,3,4,5};
    reverseArray(arr , n);
    return 0;
}