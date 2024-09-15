#include <bits/stdc++.h>
using namespace std;


vector <int> findUnion(int arr1[], int arr2[], int n1, int n2){
    map <int, int> freq;
    vector <int> Union;
    for (int i = 0; i < n1; i++)
    {
        freq[arr1[i]]++;
    }
    for (int i = 0; i < n2; i++)
    {
        freq[arr2[i]]++;
    }
    for (auto &it: freq)
    {
        Union.push_back(it.first);
    }
    return Union;
}

int main() {
  int n1 = 10, n2 = 7;
  int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int arr2[] = {2, 3, 4, 4, 5, 11, 12};
  vector < int > Union = findUnion(arr1, arr2, n1, n2);
  cout << "Union of arr1 and arr2 is " << endl;
    for (auto &val: Union)
    {
        cout << val << " ";
    }
    return 0;
}