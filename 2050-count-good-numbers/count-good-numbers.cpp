class Solution {
public:
    int MOD = 1000000007;

    int power(long long a, long long b){
        if(b == 0) return 1;

        long long half = power(a, b/2);
        long long result = (half*half) % MOD;

        if(b % 2 != 0) result = (result * a) % MOD;

        return result;
    }
    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd = n/2;

        return (long long)power(5, even) * power(4, odd) % MOD;
    }
};