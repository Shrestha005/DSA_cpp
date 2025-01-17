#include<bits/stdc++.h>
using namespace std;

string maxOdd(string s){
    int n= s.length();
    for (int i = n-1; i > 0; i--)
    {
        if(s[i] % 2 != 0){
            string str= s.substr(0,i+1);
            return str;
        }
    }
    return "";
}

int main()
{
 
    string s = "10698";
    string ans = maxOdd(s);
 
    cout << ans;
    return 0;
}