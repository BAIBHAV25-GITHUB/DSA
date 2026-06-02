class Solution {
public:
    int arrangeCoins(int n) {
        if(n == 1) return n;
        int ans = 1;
        int l = 0, h = n;
        while(l < h){
            long long m = (h+l)/2;
            if((m * (m+1) / 2) <= n){
                ans = m;
                l = m+1;
            }
            else h = m;
        }
        return ans;
    }
};