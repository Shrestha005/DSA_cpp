#include<bits/stdc++.h>
using namespace std;

//brute force can be coded by implementing stack


//optimal
string removeOuterParentheses(string s) {
    int count = 0; // To track the balance of parentheses
    string ans = ""; // Resultant string
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ')') count--; // Closing parenthesis decreases balance
        if (count != 0) ans.push_back(s[i]); // Add to result if it's not an outermost parenthesis
        if (s[i] == '(') count++; // Opening parenthesis increases balance
    }
    
    return ans;
}

int main() {

    string s1 = "(()())(())";
    cout << "Input: " << s1 << endl;
    cout << "Output: " << removeOuterParentheses(s1) << endl;

    return 0;
}
