class Solution {
public:
    // int solveUsingRec(int m, int n, int i, int j){
    //     if(i >= m || j >= n) return 0;
    //     if(i == m-1 && j == n-1) return 1;

    //     return solveUsingRec(m, n, i+1, j) + solveUsingRec(m, n, i, j+1);
    // }

    // int solveUsingMem(int m, int n, int i, int j, vector<vector<int>>& dp){
    //     if(i >= m || j >= n) return 0;
    //     if(i == m-1 && j == n-1) return 1;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     dp[i][j] = solveUsingMem(m, n, i+1, j, dp) + solveUsingMem(m, n, i, j+1, dp);
    //     return dp[i][j];
    // }

    int solveUsingTab(int m, int n){
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }

    int uniquePaths(int m, int n) {
        // return solveUsingRec(m, n, 0, 0);

        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return solveUsingMem(m, n, 0, 0, dp);

        return solveUsingTab(m, n);
    }
};