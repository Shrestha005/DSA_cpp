#include<bits/stdc++.h>
using namespace std;

void sort(int arr[], int n){
    for (int i = 0; i <= n-2; i++)
    {
        int mini= i;
        for (int j = i; j <= n-1; j++)
        {
            if(arr[j]<arr[mini]){
                mini= j; 
            }
            int temp= arr[mini];
            arr[mini]= arr[i];
            arr[i]= temp; 
            // swap(arr[mini], arr[i]);
        }  
    } 
}

int main(){
    int n;
    cin>> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>> arr[i];
    }
    sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout<< arr[i]<< endl;
    }
    return 0;
}