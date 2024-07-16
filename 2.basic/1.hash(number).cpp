#include<bits/stdc++.h>
using namespace std;

//int arr[1e7]---->this is 10^7 in case array is large. Array size upto 10^6 can be declared locally but more than that is supposed to be declared globally outside main
//so for hashing if we use array we can go 10^7 globally and 10^6 locally at max

int main(){

    //given array 
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    //precompute
    int hashh[13] = {0};
    for (int i = 0; i < n; i++)
    {
        hashh[arr[i]]+=1;
    }
    //query array
    int q;
    cin>>q;
    while (q--)
    {
        int number;
        cin>>number;
        //fetch
        cout<<hashh[number]<<endl;
    }
    return 0;
}