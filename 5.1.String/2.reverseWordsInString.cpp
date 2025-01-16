#include<bits/stdc++.h>
using namespace std;

//BRUTE 

// Use a stack to push all the words in a stack
// Now, all the words of the string are present in the stack, but in reverse order
// Pop elements of the stack one by one and add them to our answer variable. Remember to add a space between the words as well. 
// int main(){
//     string s="My Name Is Shrestha"; 
//     cout<< "Before: "<< endl;
//     cout<< s << endl;
//     s+=" ";
//     stack<string> st;
//     string str= "";
//     for (int i = 0; i < s.length(); i++)
//     {
//         if (s[i]==' ')
//         {
//             st.push(str);
//             str = "";
//         }
//         else
//         {
//             str += s[i];
//         } 
//     }
//     string ans= "";
//     while (!st.empty())
//     {
//         ans += st.top(); // Append the top word and a space
//         st.pop(); // Remove the top word from the stack

//         if (!st.empty()) { // Add a space only if more words remain
//             ans += " ";
//         }
//     }
//     cout<<"After: "<<endl;
//     cout<<ans;
//     return 0;
// }




//OPTIMAL
// We start traversing the string from the end until we hit a space. It indicates that we have gone past a word and now we need to store it.
// We check if our answer variable is empty or not
// If it’s empty, it indicates that this is the last word we need to print, and hence, there shouldn’t be any space after this word.
// If it’s empty we add it to our result with a space after it.

string result(string s){
    int left= 0; //beginning of string pointer
    int right= s.length()-1; //end of string pointer

    string temp= ""; //temporarily stores current word
    string ans= ""; //final answer stores reversed string

    while (left<=right)
    {
        char ch = s[left];

        if (ch != ' ') {
            temp += ch;
        } else if (ch == ' ') {
            if (ans!="") ans = temp + " " + ans;
            else ans = temp;
            temp = "";
        }
        left++;
    }

    if(temp != ""){
        if(ans != "") ans = temp + " " + ans;
        else ans = temp;
    }
    return ans;
}
int main()
{
    string st="My Name Is Shrestha";
    cout<<"Before:  "<<endl;
    cout<<st<<endl;
    cout<<"After: "<<endl;
    cout<<result(st);
    return 0;
}