//if we append string s1 to itself (s1) , we get all variations of its rotations

#include<bits/stdc++.h>
using namespace std;

//brute = tc is O(n^2)
// bool isRotation(string s1 , string s2){
//     if(s1.length() != s2.length()) return false;

//     //try all rotations of string s1
//     for(int i=0; i<s1.length(); i++){
//         if(s1.substr(i)+s1.substr(0,i) == s2) return true;
//     }
//     return false;
// }
// int main() {
//     cout << (isRotation("abcde", "cdeab") ? "true" : "false") << endl;
//     cout << (isRotation("abcde", "abced") ? "true" : "false") << endl;
//     return 0;
// }

//optimized = tc is O(n)
bool isRotation(string s1 , string s2){
    if(s1.length() != s2.length()) return false;
    string s3= s1+s1;
    if(s3.find(s2) == -1) return false;
    else return true;
}
int main() {
    cout << (isRotation("abcde", "cdeab") ? "true" : "false") << endl;
    cout << (isRotation("abcde", "abced") ? "true" : "false") << endl;
    return 0;
}