//optimal(using pointers)
#include <bits/stdc++.h>
using namespace std;
vector <int> findUnion(int arr1[], int arr2[], int n1, int n2){
    int i= 0, j= 0; //pointers of both arr
    vector <int> Union;
    while (i<n1 && j<n2)
    {
        if (arr1[i] <= arr2[j])
        {
            if (Union.size()==0 || Union.back() != arr1[i])
            {
                Union.push_back(arr1[i]);
            }
            i++;  
        }
        else
        {
            if (Union.size()==0 || Union.back() != arr2[j])
            {
                Union.push_back(arr2[j]);
            }
            j++;
        }
    }
    while (i<n1)
    {
        if (Union.back() != arr1[i])
        {
            Union.push_back(arr1[i]);
        }
        i++;
    }
    while (j<n2)
    {
        if (Union.back() != arr2[j])
        {
            Union.push_back(arr2[j]);
        }
        j++;
    }
    return Union;
}

int main()
{
//   int n1 = 10, n2 = 7;
//   int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//   int arr2[] = {2, 3, 4, 4, 5, 11, 12}; 
  int n1 = 6, n2 = 2;
  int arr1[] = {1,1,1,2,3,3};
  int arr2[] = {0,4}; 
  vector < int > Union = findUnion(arr1, arr2, n1, n2);
  cout << "Union of arr1 and arr2 is  " << endl;
  for (auto & val: Union)
    cout << val << " ";
  return 0;
}