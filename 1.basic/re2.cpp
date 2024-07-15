// print numbers 1 to N using recursion

#include<bits/stdc++.h>
using namespace std;

void func(int i , int n){
    if (i > n) return;

    cout << i << " "; 
    // cout << i << endl; 

    func(i+1 , n);
    
}

int main(){

    int n = 9;
    func(1 , n);
    return 0;

}
