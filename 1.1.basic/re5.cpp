// print factorial of N numbers

#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    if(n == 1){
        return 1;
    }
    return n * factorial(n - 1);
}

int main(){
    int n;
    cout << "enter a number : ";
    cin >> n;
    cout << "Factorial is " << factorial(n) << endl;
    return 0;

}
