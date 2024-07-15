#include<bits/stdc++.h>
using namespace std;
// pattern1
// * * * *
// * * * *
// * * * *
// * * * *
// pattern2
// *
// * *
// * * *
// * * * *
// * * * * *
// pattern3
// 1
// 1 2
// 1 2 3
// 1 2 3 4
// 1 2 3 4 5
// pattern4
// 1
// 2 2
// 3 3 3
// 4 4 4 4
// 5 5 5 5 5
// pattern5
// * * * * *
// * * * *
// * * *
// * *
// *
// pattern6
// 1 2 3 4 5
// 1 2 3 4
// 1 2 3
// 1 2
// 1
// pattern7
//     *
//    ***
//   *****
//  *******
// *********
// pattern8
// *********
//  *******
//   *****
//    ***
//     *
// pattern9
// call both functions 7 & 8
// pattern10
// *
// * *
// * * *
// * * * *
// * * * * *
// * * * *
// * * *
// * *
// *
// pattern11
// 1
// 01
// 101
// 0101
// 10101
// pattern12
// 1      1
// 12    21
// 123  321
// 12344321
    void print1(int n){
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++){
                cout << "* ";
            }
            cout << endl;
        }    
    }

    void print2(int n){
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cout << "* ";
            }
           cout << endl; 
        }   
    }

    void print3(int n){
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= i+1; j++)
            {
                cout << j << " ";
            }
           cout << endl; 
        }   
    }    

    void print4(int n){
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                cout << i << " ";
            }
           cout << endl; 
        }   
    }

    void print5(int n){
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < n-i+1; j++)
            {
                cout << "* ";
            }
           cout << endl; 
        }     
    }

    void print6(int n){
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n-i+1; j++)
            {
                cout << j << " ";
            }
           cout << endl; 
        }     
    }

    void print7(int n){
        for (int i = 0; i < n; i++)
        {   
            //space
            for (int j = 0; j < n-i-1; j++)
            {
                cout << " ";
            }
            //star
            for (int j = 0; j < 2*i+1; j++)
            {
                cout << "*";
            }
            //space
            for (int j = 0; j < n-i-1; j++)
            {
                cout << " ";
            }
            cout << endl;
        }
        
    }

    void print8(int n){
        for (int i = 0; i < n; i++)
        {   
            //space
            for (int j = 0; j < i; j++)
            {
                cout << " ";
            }
            //star
            for (int j = 0; j < 2*n-(2*i+1); j++)
            {
                cout << "*";
            }
            //space
            for (int j = 0; j < i; j++)
            {
                cout << " ";
            }
            cout << endl;
        }
        
    }

    void print10(int n){
        for (int i = 1; i <=2*n-1; i++)
        {
            int stars= i;
            if (i > n) stars = 2*n - i;
            for (int j = 1; j <= stars; j++)
            {
                cout << "* ";
            }
            cout << endl;
        } 
    }

    void print11(int n){
        int start = 1;
        for (int i = 0; i < n; i++)
        {
            if(i % 2 == 0) start = 1;
            else start = 0;
            for (int j = 0; j <= i; j++)
            {
                cout << start;
                start = 1 - start;
            }
            cout << endl;
        }   
    }

    void print12(int n){
        int space = 2* (n-1);
        for (int i = 1; i <= n; i++){
            //number
            for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        //space
        for (int j = 1; j <= space; j++)
        {
            cout << " ";
        }
        //number
        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }
        cout << endl;
        space -= 2;
        }  
    }


    int main(){
        int n;
        cin >> n;
        print12(n);
    return 0;
    }
