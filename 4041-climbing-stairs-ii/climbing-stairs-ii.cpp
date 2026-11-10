class Solution {
public:
    // int solveUsingRec(int i, int n, vector<int>& costs){
    //     if(i == n){
    //         return 0;
    //     }

    //     int cost = INT_MAX;

    //     int j = i+1;
    //     if(j <= n){
    //         cost = costs[j-1] + (j-i)*(j-i) + solveUsingRec(j, n, costs);
    //     }

    //     j = i+2;
    //     if(j <= n){
    //         cost = min(cost, costs[j-1] + (j-i)*(j-i) + solveUsingRec(j, n, costs));
    //     }

    //     j = i+3;
    //     if(j <= n){
    //         cost = min(cost, costs[j-1] + (j-i)*(j-i) + solveUsingRec(j, n, costs));
    //     }

    //     return cost;
    // }

    // int solveUsingMem(int i, int n, vector<int>& costs, vector<int>& dp){
    //     if(i == n){
    //         return 0;
    //     }

    //     if(dp[i] != -1) return dp[i];

    //     int cost = INT_MAX;

    //     int j = i+1;
    //     if(j <= n){
    //         cost = costs[j-1] + (j-i)*(j-i) + solveUsingMem(j, n, costs, dp);
    //     }

    //     j = i+2;
    //     if(j <= n){
    //         cost = min(cost, costs[j-1] + (j-i)*(j-i) + solveUsingMem(j, n, costs, dp));
    //     }

    //     j = i+3;
    //     if(j <= n){
    //         cost = min(cost, costs[j-1] + (j-i)*(j-i) + solveUsingMem(j, n, costs, dp));
    //     }

    //     return dp[i] = cost;
    // }

    int solveUsingTab(int n, vector<int>& costs){
        vector<int> dp(n+1, 0);

        int cost = INT_MAX;
        for(int i=n-1; i>=0; i--){
            int j = i+1;
            if(j <= n){
                cost = costs[j-1] + (j-i)*(j-i) + dp[j];
            }

            j = i+2;
            if(j <= n){
                cost = min(cost, costs[j-1] + (j-i)*(j-i) + dp[j]);
            }

            j = i+3;
            if(j <= n){
                cost = min(cost, costs[j-1] + (j-i)*(j-i) + dp[j]);
            }

            dp[i] = cost;
        }
        return dp[0];
    }

    int climbStairs(int n, vector<int>& costs) {
        // return solveUsingRec(0, n, costs);

        // vector<int> dp(n+1, -1);
        // return solveUsingMem(0, n, costs, dp);

        return solveUsingTab(n, costs);
    }
};