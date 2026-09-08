class Solution {
public:
    // int solveUsingRec(vector<vector<int>>& grid, int i, int j){
    //     int m=grid.size(), n=grid[0].size();
    //     if(i >= m || j >= n) return 0;
    //     if(grid[i][j] == 1) return 0;

    //     if(i == m-1 && j == n-1 && grid[i][j] == 0) return 1;

    //     return solveUsingRec(grid, i+1, j)+solveUsingRec(grid, i, j+1); 
    // }

    int solveUsingMem(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
        int m=grid.size(), n=grid[0].size();
        if(i >= m || j >= n) return 0;
        if(grid[i][j] == 1) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(i == m-1 && j == n-1 && grid[i][j] == 0) return 1;

        dp[i][j] = solveUsingMem(grid, i+1, j, dp)+solveUsingMem(grid, i, j+1, dp);
        return dp[i][j]; 
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // return solveUsingRec(obstacleGrid, 0, 0);

        int m=obstacleGrid.size(), n=obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solveUsingMem(obstacleGrid, 0, 0, dp);
    }
};