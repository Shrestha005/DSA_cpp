//tc is O(log n)


class Solution {
public:

    int MOD = 1e9 + 7;  


    int countGoodNumbers(long long n) {
        long long evenindex= (n+1)/2;
        long long oddindex= n/2;

        long long even_choice= mypow(5,evenindex , MOD);
        long long prime_choice= mypow(4,oddindex , MOD);

        return (int)((even_choice*prime_choice)%MOD);
    }
    long long mypow(long long x, long long n, int MOD){
        x=x%MOD;
        long long ans= 1.0;
        while(n>0){
            if(n%2==1){
                ans=(ans*x)%MOD;
            }
            x=(x*x)%MOD;
            n=n/2;
        }
        return ans;
    }
};