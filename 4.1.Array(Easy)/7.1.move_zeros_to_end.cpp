//brute
#include <bits/stdc++.h>
using namespace std;

vector<int> moveZerosToEnd(vector<int> a, int n){
    vector<int> temp;

    for (int i = 0; i < n; i++)
    {
        if (a[i]!= 0)
        {
            //pushing nonzero elements to temp array
            temp.push_back(a[i]);
        }   
        int nz= temp.size();

        for (int i = 0; i < nz; i++)
        {
            //stores the non zero elements again back to org arr 'a' from temp till nz elements
            a[i]= temp[i];
        }
        for (int i = nz; i < n; i++)
        {
            a[i]= 0;
        }
        return a;
    } 
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
