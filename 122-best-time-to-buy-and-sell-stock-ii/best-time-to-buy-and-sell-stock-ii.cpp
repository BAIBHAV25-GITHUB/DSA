class Solution {
public:
    // int solveUsingRec(vector<int>& prices, int day, int canBuy){
    //     int n=prices.size();
        
    //     if(day == n){
    //         return 0;
    //     }

    //     if(canBuy){
    //         int buy = -prices[day] + solveUsingRec(prices, day+1, 0);
    //         int skip = solveUsingRec(prices, day+1, 1);
    //         return max(buy, skip);
    //     }

    //     int sell = prices[day] + solveUsingRec(prices, day+1, 1);
    //     int hold = solveUsingRec(prices, day+1, 0);

    //     return max(sell, hold);
    // }

    // int solveUsingMem(vector<int>& prices, int day, int canBuy, vector<vector<int>>& dp){
    //     int n=prices.size();
        
    //     if(day == n){
    //         return 0;
    //     }
    //     if(dp[day][canBuy] != -1) return dp[day][canBuy];

    //     int profit = 0;
    //     if(canBuy){
    //         int buy = -prices[day] + solveUsingMem(prices, day+1, 0, dp);
    //         int skip = solveUsingMem(prices, day+1, 1, dp);
    //         profit = max(buy, skip);
    //     }
    //     else{
    //         int sell = prices[day] + solveUsingMem(prices, day+1, 1, dp);
    //         int hold = solveUsingMem(prices, day+1, 0, dp);

    //         profit = max(sell, hold);
    //     }
        
    //     return dp[day][canBuy] = profit;
    // }

    int solveUsingTab(vector<int>& prices){
        int n=prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for(int i=n-1; i>=0; i--){
            int buy = -prices[i] + dp[i+1][0];
            int skip = dp[i+1][1];
            dp[i][1] = max(buy, skip);

            int sell = prices[i] + dp[i+1][1];
            int hold = dp[i+1][0];
            dp[i][0] = max(sell, hold);
        }

        return dp[0][1];
    }

    int maxProfit(vector<int>& prices) {
        // return solveUsingRec(prices, 0, 1);

        // int n=prices.size();
        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return solveUsingMem(prices, 0, 1, dp);

        return solveUsingTab(prices);
    }
};