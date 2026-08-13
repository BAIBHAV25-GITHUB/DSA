class Solution {
public:
    // int solve(vector<int>& coins, int amount, vector<int>& dp){
    //     if(amount < 0) return -1;
    //     if(amount == 0) return 0;
    //     if(dp[amount] != -1) return dp[amount];

    //     int mini = INT_MAX;
    //     for(int c:coins){
    //         int res = solve(coins, amount-c, dp);
    //         if(res >= 0 && res < mini){
    //             mini = 1+res; 
    //         }
    //     }

    //     dp[amount] = (mini == INT_MAX)? -1:mini;
    //     return dp[amount];
    // }   
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for(int i=1; i<= amount; i++){
            for(int c:coins){
                if(i-c >= 0){
                    dp[i] = min(dp[i], 1+dp[i-c]);
                }
            }
        }
        return (dp[amount] > amount )? -1:dp[amount]; 
    }
};