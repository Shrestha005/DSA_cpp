#include<bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
        int sign=1;
        int i=0;
        long result=0;

        while(i< s.length() && s[i]==' ') i++;
        
        if (i < s.length() && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while(i<s.length() && isdigit(s[i])){
            result= result*10 + s[i]-'0';

            if (result * sign > INT_MAX) return INT_MAX;
            if (result * sign < INT_MIN) return INT_MIN;

            i++;
        }
        return result*sign;
}
int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;
    int num = myAtoi(str);
    cout << "Converted integer: " << num << endl;
    return 0;
}

