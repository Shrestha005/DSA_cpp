#include<bits/stdc++.h>
using namespace std;

void sort(int arr[], int n){
    for (int i = n-1; i >= 1; i--)
    {
    int didSwap= 0;
        for (int j = 0; j <= i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp= arr[j];
                arr[j]= arr[j+1];
                arr[j+1]= temp;
                didSwap= 1;
            }          
        }  
        if (didSwap==0)
        {
            break;
        }   
        cout<<"runs\n"; //to check how many times in runs(helps to identofy the best case and worst avg)   
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