class Solution {
public:
    // int solveUsingRec(vector<vector<int>>& grid, int i, int j){
    //     int m=grid.size(), n=grid[0].size();
    //     if(i >= m || j >= n) return 0;
    //     if(grid[i][j] == 1) return 0;

    //     if(i == m-1 && j == n-1 && grid[i][j] == 0) return 1;

    //     return solveUsingRec(grid, i+1, j)+solveUsingRec(grid, i, j+1); 
    // }

    // int solveUsingMem(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
    //     int m=grid.size(), n=grid[0].size();
    //     if(i >= m || j >= n) return 0;
    //     if(grid[i][j] == 1) return 0;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     if(i == m-1 && j == n-1 && grid[i][j] == 0) return 1;

    //     dp[i][j] = solveUsingMem(grid, i+1, j, dp)+solveUsingMem(grid, i, j+1, dp);
    //     return dp[i][j]; 
    // }

    int solveUsingTab(vector<vector<int>>& grid){
        long long m=grid.size(), n=grid[0].size();
        vector<vector<long long>> dp(m, vector<long long>(n, 0));

        if(dp[m-1][n-1] == 1) return 0;
        dp[m-1][n-1] = 1;

        for(long long i=m-1; i>=0; i--){
            for(long long j=n-1; j>=0; j--){
                if(grid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                }

                if(i == m-1 && j == n-1) continue;

                long long down = 0, right = 0;
                if(i+1 < m) down = dp[i+1][j];
                if(j+1 < n) right = dp[i][j+1];

                dp[i][j] = down + right; 
            }
        }
        return dp[0][0];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // return solveUsingRec(obstacleGrid, 0, 0);

        // int m=obstacleGrid.size(), n=obstacleGrid[0].size();
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return solveUsingMem(obstacleGrid, 0, 0, dp);

        return solveUsingTab(obstacleGrid);
    }
};