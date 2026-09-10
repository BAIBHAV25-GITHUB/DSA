class Solution {
public:
    // int solveUsingRec(vector<vector<int>>& triangle, int i, int j){
    //     int n=triangle.size();
    //     if(i == n) return 0;

    //     int down = triangle[i][j] + solveUsingRec(triangle, i+1, j);
    //     int right = triangle[i][j] + solveUsingRec(triangle, i+1, j+1);

    //     return min(down, right);
    // } 

    // int solveUsingMem(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& dp){
    //     int n=triangle.size();
    //     if(i == n) return 0;

    //     if(dp[i][j] != -1) return dp[i][j];
    //     int down = triangle[i][j] + solveUsingMem(triangle, i+1, j, dp);
    //     int right = triangle[i][j] + solveUsingMem(triangle, i+1, j+1, dp);

    //     dp[i][j] = min(down, right);
    //     return dp[i][j];
    // }

    // int solveUsingTab(vector<vector<int>>& triangle){
    //     int n=triangle.size();
    //     vector<vector<int>> dp(n, vector<int>(n, -1));

    //     for(int j=0; j<n; j++){
    //         dp[n-1][j] = triangle[n-1][j];
    //     }

    //     for(int i=n-2; i>=0; i--){
    //         for(int j=0; j<i+1; j++){
    //             int down = triangle[i][j] + dp[i+1][j];
    //             int right = triangle[i][j] + dp[i+1][j+1];
    //             dp[i][j] = min(down, right);
    //         }
    //     }
    //     return dp[0][0];
    // } 

    int solve(vector<vector<int>>& triangle){
        int n=triangle.size();
        vector<int> curr(n, 0);
        vector<int> next(triangle[n-1]);

        for(int i=n-2; i>=0; i--){
            for(int j=0; j<i+1; j++){
                int down = triangle[i][j] + next[j];
                int right = triangle[i][j] + next[j+1];
                curr[j] = min(down, right);
            }
            next = curr;
        }
        return next[0];
    } 

    int minimumTotal(vector<vector<int>>& triangle) {
        // return solveUsingRec(triangle, 0, 0);

        // int n=triangle.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return solveUsingMem(triangle, 0, 0, dp);

        // return solveUsingTab(triangle);

        return solve(triangle);
    }
};