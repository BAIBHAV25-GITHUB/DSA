class Solution {
public:
    // int solveUsingRec(vector<vector<int>>& grid, int i, int j){
    //     int m = grid.size(), n = grid[0].size();
    //     if(i >= m || j >= n) return 1e9;
    //     if(i == m-1 && j == n-1) return grid[m-1][n-1];

    //     int down = grid[i][j] + solveUsingRec(grid, i+1, j);
    //     int right = grid[i][j] + solveUsingRec(grid, i, j+1);

    //     return min(down, right);
    // }

    int solveUsingMem(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
        int m = grid.size(), n = grid[0].size();
        if(i >= m || j >= n) return 1e9;
        if(i == m-1 && j == n-1) return grid[m-1][n-1];

        if(dp[i][j] != -1) return dp[i][j];

        int down = grid[i][j] + solveUsingMem(grid, i+1, j, dp);
        int right = grid[i][j] + solveUsingMem(grid, i, j+1, dp);

        return dp[i][j] = min(down, right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        // return solveUsingRec(grid, 0, 0);

        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solveUsingMem(grid, 0, 0, dp);
    }
};