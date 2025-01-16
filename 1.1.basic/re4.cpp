// print sum of N numbers

#include<bits/stdc++.h>
using namespace std;

int sum(int n){
    if(n == 0){
        return 0;
    }
    return n + sum(n - 1);
}

int main(){
    int n;
    cout << "enter a number : ";
    cin >> n;
    cout << "Sum is " << sum(n) << endl;
    return 0;

}
