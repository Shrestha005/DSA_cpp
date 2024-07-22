#include <bits/stdc++.h>
using namespace std;

int second_largest(int arr[], int n){
    int largest= arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i]> largest)
        {
            largest= arr[i];
        } 
    }
    int s_largest= -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]> s_largest && arr[i]!= largest)
        {
            s_largest= arr[i];
        }   
    } 
    return s_largest;   
}


int main(){
    int arr[]= {2,5,9,11,14};
    // int arr[]= {2,2,2,2,2};
    int n= 5;
    int secondLargest = second_largest(arr, n);
    cout<< "The second largest element in the array is : "<< secondLargest<< endl;
    return 0;
}