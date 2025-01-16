#include <bits/stdc++.h>
using namespace std;

vector<int> moveZerosToEnd(vector<int> a, int n){
    int j= -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            j = i;
            break;
        }  
    }
    if (j == -1)
    {
        return a; //means there is no 0 
    }
    for (int i = j+1; i < n; i++)
    {
        if (a[i] != 0)
        {
            swap(a[i], a[j]);
            j++;
        }  
    }    
    return a;
}

int main()
{
    vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    int n = 10;
    vector<int> ans = moveZerosToEnd(arr, n);
    for (auto &it : ans) {
        cout << it << " ";
    }
    cout << '\n';
    return 0;
}


