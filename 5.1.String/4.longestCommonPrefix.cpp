#include<bits/stdc++.h>
using namespace std;

//brute(matching each character)

// string lcp(vector<string> &arr){
//     int minLen= arr[0].length();
//     for (string &str : arr)
//     {
//         minLen= min(minLen , (int)str.size());        
//     }
//     string result;
//     for (int i = 0; i < minLen; i++)
//     {
//         char ch= arr[0][i];
//         for (string &str : arr)
//         {
//             if(str[i] != ch) return result;
//         }
//         result.push_back(ch);
//     }
//     return result;
// }
// int main() {
//     vector<string> arr = {"apples", "apple", "appletree", "appyfizz"};
//     cout << lcp(arr);
//     return 0;
// }



//optimal

string lcp(vector<string> &arr){
    sort(arr.begin(),arr.end());

    string first= arr.front(); //smallest
    string last= arr.back(); //largest

    int minLength= min(first.size(),last.size());

    int i= 0;

    while (i<minLength && first[i]==last[i])
    {
        i++;
    }
    return first.substr(0,i);
}

int main() {
    vector<string> arr = {"apples", "apple", "appletree", "appyfizz"};
    cout << lcp(arr) << endl;
    return 0;
}