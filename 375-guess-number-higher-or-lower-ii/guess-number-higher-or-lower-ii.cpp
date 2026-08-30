class Solution {
public:
    // int solveUsingRec(int start, int end){
    //     if(start >= end) return 0;

    //     int ans = INT_MAX;
    //     for(int i=start; i<= end; i++){
    //         ans = min(ans, i+max(solveUsingRec(start, i-1), solveUsingRec(i+1, end)));
    //     }
    //     return ans;
    // }

    int solveUsingMem(int start, int end,vector<vector<int>>& dp){
        if(start >= end) return 0;
        if(dp[start][end] != -1) return dp[start][end];
        
        int ans = INT_MAX;
        for(int i=start; i<= end; i++){
            ans = min(ans, i+max(solveUsingMem(start, i-1, dp), solveUsingMem(i+1, end, dp)));
        }
        return dp[start][end] = ans;
    }

    int getMoneyAmount(int n) {
        // return solveUsingRec(1, n);

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solveUsingMem(1, n, dp);
    }
};