class Solution {
public:
    // int solveUsingRec(int day, int canBuy, vector<int>& prices, int fee){
    //     int n=prices.size();
    //     if(day == n) return 0;

    //     if(canBuy == 1){
    //         int buy = -prices[day] + solveUsingRec(day+1, 0, prices, fee);
    //         int skip = solveUsingRec(day+1, 1, prices, fee);

    //         return max(buy, skip);
    //     }

    //     int sell = prices[day] - fee + solveUsingRec(day+1, 1, prices, fee);
    //     int hold = solveUsingRec(day+1, 0, prices, fee);

    //     return max(sell, hold);
    // }

    // int solveUsingMem(int day, int canBuy, vector<int>& prices, int fee, vector<vector<int>>& dp){
    //     int n=prices.size();
    //     if(day == n) return 0;

    //     if(dp[day][canBuy] != -1) return dp[day][canBuy];

    //     int profit = 0;
    //     if(canBuy == 1){
    //         int buy = -prices[day] + solveUsingMem(day+1, 0, prices, fee, dp);
    //         int skip = solveUsingMem(day+1, 1, prices, fee, dp);

    //         profit = max(buy, skip);
    //     }
    //     else{
    //         int sell = prices[day] - fee + solveUsingMem(day+1, 1, prices, fee, dp);
    //         int hold = solveUsingMem(day+1, 0, prices, fee, dp);

    //         profit = max(sell, hold);
    //     }

    //     return dp[day][canBuy] = profit;
    // }

    int solveUsingTab(vector<int>& prices, int fee){
        int n=prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for(int i=n-1; i>=0; i--){
            int buy = -prices[i] + dp[i+1][0];
            int skip = dp[i+1][1];

            dp[i][1] =  max(buy, skip);

            int sell = prices[i] - fee + dp[i+1][1];
            int hold = dp[i+1][0];

            dp[i][0] = max(sell, hold);
        }
        return dp[0][1];
    }

    int maxProfit(vector<int>& prices, int fee) {
        // return solveUsingRec(0, 1, prices, fee);

        // int n=prices.size();
        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return solveUsingMem(0, 1, prices, fee, dp);

        return solveUsingTab(prices, fee);
    }
};