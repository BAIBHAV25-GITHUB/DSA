class Solution {
public:
    int reverseNum(int x){
        int ans = 0;
        while(x > 0){
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }
    int mirrorDistance(int n) {
        return abs(n - reverseNum(n));
    }
};