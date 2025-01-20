#include<bits/stdc++.h>
using namespace std;

//brute
// bool isIsomorphic(string s1, string s2){
//     //case 1
//     if(s1.length() != s2.length()) return false;
//     //case 2
//     for (int i = 0; i < s1.length(); i++)
//     {
//         for (int j = i+1; j < s1.length(); j++)
//         {
//             if((s1[i] != s1[j] && s2[i] == s2[j]) || (s1[i] == s1[j] && s2[i] != s2[j])){
//                 return false;
//             }
//         }
//     }
//     return true;
// }
// int main() {
//     cout << (isIsomorphic("aab", "xxy") ? "True" : "False");
//     return 0;
// }

//optimal

bool isIsomorphic(const string &s1, const string &s2) {
    if (s1.length() != s2.length()) return false;
    unordered_map<char , char> m1 , m2;
    for (int i = 0; i < s1.length(); i++)
    {
        //If character did not occur before, store its first occurrence index
        if(m1.find(s1[i]) == m1.end()){
            m1[s1[i]] = i;
        }
        if(m2.find(s2[i]) == m2.end()){
            m2[s2[i]] = i;
        }
        // Check if the first occurrence index match
        if(m1[s1[i] != m2[s2[i]]]){
            return false;
        }
    }
    return true;
}
int main() {
    cout << (isIsomorphic("aab", "xxy") ? "True" : "False");
    return 0;
}