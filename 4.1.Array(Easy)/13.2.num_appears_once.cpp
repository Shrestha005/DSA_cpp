//better approach 1
//Array hashing:

#include <bits/stdc++.h>
using namespace std;

int getSingleElement(vector<int> &arr){
    int n= arr.size(); // size of array

    int maxi= arr[0]; // find max element
    for (int i = 0; i < n; i++)
    {
        maxi= max(arr[i], maxi);
    }
    //array of size maxi+1
    //hash array
    vector<int> hash(maxi+1, 0);
        for (int i = 0; i < n; i++)
        {
            hash[arr[i]]++;
        }
        
    //answer
    for (int i = 0; i < n; i++) {
        if (hash[arr[i]] == 1)
            return arr[i];
        }
    return -1;
}

int main()
{
    vector<int> arr = {4, 1, 2, 1, 2};
    int ans = getSingleElement(arr);
    cout << "The single element is: " << ans << endl;
    return 0;
}

