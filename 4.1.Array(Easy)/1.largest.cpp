#include <bits/stdc++.h>
using namespace std;

int largest(int arr[], int n){
    int max= arr[0];
    for (int i = 0; i < n; i++)
    {
        if (max< arr[i])
        {
            max= arr[i];
        }    
    } 
    return max;
}

int main(){
    int arr[]= {2,5,9,0,14};
    int n= 5;
    int max= largest(arr, n);
    cout<< "The largest element in the array is : "<< max<< endl;
    return 0;
}