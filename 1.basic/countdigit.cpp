#include<bits/stdc++.h>
using namespace std;

// 1

int count(int n){
    int cnt = 0;
    while (n>0)
    {
        // int lastdigit = n % 10;
        cnt = cnt + 1;
        n = n / 10;
    }
    return cnt;
}

// 2

int count(int n){
    int cnt = (int) (log10(n) + 1);
    return cnt;
}