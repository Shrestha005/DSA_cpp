//VARIETY 1
//in an array equal number of positive and negative numbers will be given 
//task is to arrange it as alternate positives and negatives
//sorting is not necessary but the original array order of positives and negatives must be maintained

#include<bits/stdc++.h>
using namespace std;

//BRUTE
 vector<int> RearrangebySign(vector<int>A, int n){    
  // Define 2 vectors, one for storing positive 
  // and other for negative elements of the array.
  vector<int> pos;
  vector<int> neg; 
  // Segregate the array into positives and negatives.
  for(int i=0;i<n;i++){      
      if(A[i]>0) pos.push_back(A[i]);
      else neg.push_back(A[i]);
  }  
  // Positives on even indices, negatives on odd.
  for(int i=0;i<n/2;i++){     
      A[2*i] = pos[i];
      A[2*i+1] = neg[i];
  }
  return A;   
}


//OPTIMAL
vector<int> RearrangebySign(vector<int>A){    
  int n = A.size(); 
  // Define array for storing the ans separately.
  vector<int> ans(n,0); 
  // positive elements start from 0 and negative from 1.
  int posIndex = 0, negIndex = 1;
  for(int i = 0;i<n;i++){      
      // Fill negative elements in odd indices and inc by 2.
      if(A[i]<0){
          ans[negIndex] = A[i];
          negIndex+=2;
      }   
      // Fill positive elements in even indices and inc by 2.
      else{
          ans[posIndex] = A[i];
          posIndex+=2;
      }
  }
  return ans;   
}


int main() {  
  // Array Initialisation.
  int n = 4;
  vector<int> A {1,2,-4,-5};
  vector<int> ans = RearrangebySign(A,n);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  return 0;
}