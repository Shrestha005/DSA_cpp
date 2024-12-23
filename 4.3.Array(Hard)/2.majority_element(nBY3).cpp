#include <bits/stdc++.h>
using namespace std;

//brute
// vector<int> majorityElement(vector<int> v){
//     int n= v.size();
//     vector<int> ls; //list= answer
//     for (int i = 0; i < n; i++)
//     {
//         if(ls.size()==0 || ls[0]!=v[i]){
//             int cnt= 0;
//             for (int j = 0; j < n; j++)
//             {
//                 if(v[j]==v[i]){
//                     cnt++;
//                 }
//             }
//             if(cnt> (n/3)){
//                 ls.push_back(v[i]);
//             }
//         }
//         if(ls.size()==2) break;
//     }
//     return ls;
// }
// int main()
// {
//     vector<int> arr = {11, 33, 33, 11, 33, 11};
//     vector<int> ans = majorityElement(arr);
//     cout << "The majority elements are: ";
//     for (auto it : ans)
//         cout << it << " ";
//     cout << "\n";
//     return 0;
// }

//better
// vector<int> majorityElement(vector<int> v){
//     int n= v.size();
//     vector<int> ls; //list= answer
//     map<int, int> mpp; //map for cnt (unique ele as key and their cnt as value)
//     int mini= int(n/3)+1;
//     for (int i = 0; i < n; i++)
//     {
//         mpp[v[i]]++;
//         if(mpp[v[i]]==mini){
//             ls.push_back(v[i]);
//         }
//         if(ls.size()==2) break;
//     }
//     return ls;
// }    
// int main()
// {
//     vector<int> arr = {11, 33, 33, 11, 33, 11};
//     vector<int> ans = majorityElement(arr);
//     cout << "The majority elements are: ";
//     for (auto it : ans)
//         cout << it << " ";
//     cout << "\n";
//     return 0;
// }

//optimal (Boyer Moore’s Voting Algorithm)
vector<int> majorityElement(vector<int> v) {
    int n = v.size();
    int cnt1=0, cnt2=0;
    int ele1= INT_MIN, ele2= INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if(cnt1==0 && ele2!=v[i]){
            cnt1= 1;
            ele1= v[i];
        }
        else if(cnt2==0 && ele2!=v[i]){
            cnt2= 1;
            ele2= v[i];
        }
        else if(v[i]==ele1) cnt1++;
        else if(v[i]==ele2) cnt2++;
        else{
            cnt1--, cnt2--;
        }
    }
    vector<int> ls;

    //manual check
    cnt1=0, cnt2=0;
    for (int i = 0; i < n; i++)
    {
        if(v[i]==ele1) cnt1++;
        if(v[i]==ele2) cnt2++;
    }
    int mini= int(n/3)+1;
    if (cnt1 >= mini) ls.push_back(ele1);
    if (cnt2 >= mini) ls.push_back(ele2);
    return ls;
}
int main()
{
    vector<int> arr = {11, 33, 33, 11, 33, 11};
    vector<int> ans = majorityElement(arr);
    cout << "The majority elements are: ";
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";
    return 0;
}
