class Solution {
public:
    // int solveUsingMemo(int n, vector<int>& dp){
    //     if(n==0 || n==1) return n;

    //     if(dp[n] != -1){
    //         return dp[n];
    //     }

    //     int ans = fib(n-1) + fib (n-2);
    //     dp[n] = ans;
    //     return dp[n];
    // } 

    int solveUsingTab(int n){
        vector<int> dp(n+1, -1);
        dp[0] = 0, dp[1] = 1;

        for(int i=2; i<=n ; i++){
            dp[i] = dp[i-1]+dp[i-2];
        }

        return dp[n];
    }

    int fib(int n) {
        // vector<int> dp(n+1, -1);
        // int ans = solveusingMemo(n, dp);
        // return ans;
        if(n == 0 || n == 1) return n;
        int ans = solveUsingTab(n);
        return ans;
    }
};