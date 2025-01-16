#include <bits/stdc++.h>
using namespace std;

//second largest
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

//second smallest
int second_smallest(int arr[], int n){
    int smallest= arr[0];
    int s_smallest= INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]< smallest)
        {
        s_smallest= smallest;
        smallest= arr[i];
        }
        else if (arr[i]!= smallest && arr[i]< s_smallest)
        {
        s_smallest= arr[i];
        }  
    }
    return s_smallest; 
}



int main(){
    int arr[]= {2,5,9,11,14};
    // int arr[]= {2,2,2,2,2};
    int n= 5;
    int secondLargest = second_largest(arr, n);
    int secondSmallest = second_smallest(arr, n);
    cout<< "The second largest element in the array is : "<< secondLargest<< endl;
    cout<< "The second largest element in the array is : "<< secondSmallest<< endl;
    return 0;
}