#include <bits/stdc++.h> 
using namespace std;

bool isArmstrong(int num){
    int k= to_string(num).length();
    // int sum = 0;
    double sum = 0;
    int n = num;

    while (n > 0)
    {
        int ld = n % 10;
        sum += pow(ld , k);
        n = n / 10;
    }
    return sum == num ? true : false;
}

int main(){
    int num;

    cout << "enter a number : ";
    cin >> num ;
    if (isArmstrong(num))
    {
        cout << num << " is an Armstrong number." << endl;
    } else
    {
        cout << num << " is not an Armstrong number." << endl;
    } 
    return 0;
}