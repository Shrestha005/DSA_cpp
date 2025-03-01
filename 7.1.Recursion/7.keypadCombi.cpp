#include<bits/stdc++.h>
using namespace std;

//BRUTE O(4ⁿ * n)

// class Solution {
//     public:
//         void combi(int ind, string &digits, string &current, vector<string> &ans, vector<string> &keypad){
//             int n= digits.size();
//             if(ind==n){
//                 ans.push_back(current);
//                 return;
//             }
//             string letters= keypad[digits[ind]-'0'];
//             for(char letter: letters){
//                 current.push_back(letter);
//                 combi(ind+1, digits, current, ans, keypad);
//                 current.pop_back();
//             }
//         }
    
//         vector<string> letterCombinations(string digits) {
//             if(digits.empty()) return {};
    
//             vector<string> keypad= {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
//             vector<string> ans;
//             string current= "";
//             combi(0, digits, current, ans, keypad);
//             return ans;
//         }
//     };


// OPTIMAL O(4ⁿ)
class Solution {
    public:
        void combi(int ind, const string &digits, string &current, vector<string> &ans, const vector<string> &keypad){
            int n= digits.size();
            if(ind==n){
                ans.push_back(current);
                return;
            }
            for(char letter: keypad[digits[ind]-'0']){
                current.push_back(letter);
                combi(ind+1, digits, current, ans, keypad);
                current.pop_back();
            }
        }
    
        vector<string> letterCombinations(string digits) {
            if(digits.empty()) return {};
    
            static const vector<string> keypad= {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
            vector<string> ans;
            string current= "";
            combi(0, digits, current, ans, keypad);
            return ans;
        }
    };



// Slightly slower due to unnecessary re-initialization & less efficient memory access.

//Faster due to static const, better memory management, and optimized parameter passing.