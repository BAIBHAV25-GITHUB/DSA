class Solution {
public:
    int MOD = 1e9+7;
    // int solveUsingRec(int n, int k, int target){
    //     if(n<0 || target<0) return 0;

    //     if(n == 0 && target == 0) return 1;

    //     if(n == 0 && target != 0) return 0;

    //     if(n != 0 && target == 0) return 0; 

    //     int ans = 0;
    //     for(int i=1; i<=k; i++){
    //         ans = 1+solveUsingRec(n-1, k, target-i); 
    //     }
    //     return ans;
    // } 

    int solveUsingMem(int n, int k, int target, vector<vector<int>>& dp){
        if(n<0 || target<0) return 0;

        if(n == 0 && target == 0) return 1;

        if(n == 0 && target != 0) return 0;

        if(n != 0 && target == 0) return 0; 

        if(dp[n][target] != -1) return dp[n][target];

        int ans = 0;
        for(int i=1; i<=k; i++){
            ans = ((ans%MOD) + solveUsingMem(n-1, k, target-i, dp))%MOD;  
        }
        dp[n][target] = ans;
        return dp[n][target];
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return solveUsingMem(n, k, target, dp);
    }
}; 