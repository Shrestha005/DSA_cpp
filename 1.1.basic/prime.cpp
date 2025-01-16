#include<bits/stdc++.h>
using namespace std;

bool checkPrime(int n){
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            count++;
        }    
    }  
    if (count == 2)
    {
        return true;
    }
    else
    {
        return false;
    }   
}

int main(){
    int n;
    cout << "Enter a number : ";
    cin >> n;
    bool isPrime = checkPrime(n);
    if (isPrime)
    {
        cout << n << " is a prime number." << endl;
    }
    else 
    {
        cout << n << " is not a prime number." << endl;
    }
    return 0;
}