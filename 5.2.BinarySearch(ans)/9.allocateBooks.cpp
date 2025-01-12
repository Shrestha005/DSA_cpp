#include <bits/stdc++.h>
using namespace std;

int countStudents(vector<int> &arr, int page){
    int n= arr.size();
    int student=1;
    int studentPage=0;
    for(int i=0; i<n; i++){
        if(studentPage + arr[i] <= page){
            studentPage += arr[i];
        }
        else{
            student++;
            studentPage = arr[i];
        }
    }
    return student;
}

// int pageCount(vector<int> &arr, int m){
//     int n=arr.size();
//     int low= *max_element(arr.begin(), arr.end());
//     int high= accumulate(arr.begin(), arr.end(), 0);
//     for (int page = low; page < high; page++)
//     {
//         int cntStudent= countStudents(arr , page);
//         if(cntStudent==m) return page;
//     }
//     return low;
// }

int pageCount(vector<int> &arr, int m){
    int n=arr.size();
    int low= *max_element(arr.begin(), arr.end());
    int high= accumulate(arr.begin(), arr.end(), 0);
    while (low<=high)
    {
        int mid= (low+high)/2;
        int cntStudent= countStudents(arr , mid);
        if (cntStudent>m) low= mid+1;
        else high= mid-1;
    }
    return low;
}


int main()
{
    vector<int> arr = {25, 46, 28, 49, 24};
    int m = 4;
    int ans = pageCount(arr, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}