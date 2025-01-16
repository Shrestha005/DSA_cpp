// an array of distinct elements will be given and a separate digit will be given (suppose x)
// if x is already present in the array return its index
// if not present return the index where it should be inserted while maintaining the sorted order
#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int> &arr, int x){
    int n= arr.size();
    //just copy the lowerbound code from here
    int low= 0, high= n-1;
    int index= n;
    while (low <= high)
    {
        int mid= (low+high)/2;

        if(arr[mid] >= x){
            index= mid;
            high= mid-1;
        }
        else{
            low= mid+1;
        }
    }
    return index;
}
int main()
{
    vector<int> arr = {1, 2, 4, 7};
    int x = 6;
    int ind = searchInsert(arr, x);
    cout << "The index is: " << ind << "\n";
    return 0;
}