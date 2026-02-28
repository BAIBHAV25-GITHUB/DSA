class Solution {
public:
    int mod = 1e9+7; 
    int concatenatedBinary(int n) {
        long res = 0;
        for(int i = 1; i <= n; i++){
            int digit = log2(i) + 1;

            res = ((res << digit)%mod + i) % mod;
        }
        return res;
    }
};