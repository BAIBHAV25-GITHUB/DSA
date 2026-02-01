class Solution {
public:
    int numSub(string s) {
        int MOD = 1000000007;
        int ans = 0 , cnt = 0;
        for(char c:s){
            if(c == '1'){
                cnt++;
                ans = (ans + cnt) % MOD;
            }
            else cnt = 0; 
        }
        return ans;
    }
};