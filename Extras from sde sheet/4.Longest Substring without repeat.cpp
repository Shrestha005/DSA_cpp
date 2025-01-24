#include<bits/stdc++.h>
using namespace std;

//brute
// int solve(string str) {
//   if(str.size()==0)
//       return 0;
//   int maxans = INT_MIN;
//   for (int i = 0; i < str.length(); i++) 
//   {
//     unordered_set < int > set;
//     for (int j = i; j < str.length(); j++) 
//     {
//       if (set.find(str[j]) != set.end()) // if element if found so mark it as ans and break from the loop
//       {
//         maxans = max(maxans, j - i);
//         break;
//       }
//       set.insert(str[j]);
//     }
//   }
//   return maxans;
// }
// int main() {
//   string str = "abcaaabbc";
//   cout << "The length of the longest substring without repeating characters is " << solve(str);
//   return 0;
// }


//optimal
int solve(string str) {
  if(str.size()==0)
      return 0;
  int maxans = INT_MIN;
  unordered_set < int > set;
  int l = 0;
  for (int r = 0; r < str.length(); r++)
  {
    if (set.find(str[r]) != set.end()) //if duplicate element is found
    {
      while (l < r && set.find(str[r]) != set.end()) {
        set.erase(str[l]);
        l++;
      }
    }
    set.insert(str[r]);
    maxans = max(maxans, r - l + 1);
  }
  return maxans;
}
int main() {
  string str = "abcaaabbc";
  cout << "The length of the longest substring without repeating characters is " << solve(str)<< endl;
  return 0;
}