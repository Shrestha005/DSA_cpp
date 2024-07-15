// #include<bits/stdc++.h>
// using namespace std;

// int fibo(int n){
//     if (n<=1)
//     {
//         return n;
//     }
    
//     int last = fibo(n-1);
//     int second_last = fibo(n-2);

//     return last + second_last;
// }

// int main(){
//     int n;
//     cout<<"enter number : ";
//     cin>>n;
//     cout<<fibo(n)<<endl;
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;

int main() {
  int n = 5;
  if (n == 0) {
    cout << 0;
  } else if (n == 1) {
    cout << 0 << " " << 1 << "\n";
  } else {
    int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
      fib[i] = fib[i - 1] + fib[i - 2];
    }
    cout<<"The Fibonacci Series up to "<<n<<"th term:"<<endl;
    for (int i = 0; i <= n; i++) {
      cout << fib[i] << " ";
    }
  }
}