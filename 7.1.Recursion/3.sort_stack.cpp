#include<bits/stdc++.h>
using namespace std;

void insert_corr_pos(int x, stack<int> &s){
    if(s.size()==0 || s.top()<x){
        s.push(x);
        return;
    }
    else{
        int a= s.top();
        s.pop();
        insert_corr_pos(x,s);
        s.push(a);
    }
}

void sortStack(stack<int> &s){
    if(s.size()==0) return;
    int x= s.top();
    s.pop();
    sortStack(s);
    insert_corr_pos(x,s);
}


class SortedStack {
    public:
        stack<int> s;
        
        void sort() {
            sortStack(s);
        }
    };