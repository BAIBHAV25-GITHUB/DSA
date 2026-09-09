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

    int solveUsingTab(vector<vector<int>>& grid){
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(i == m-1 && j == n-1){
                    dp[i][j] = grid[i][j];
                }
                else{
                    int down = grid[i][j];
                    if(i < m-1) down += dp[i+1][j];
                    else down += 1e9;

                    int right = grid[i][j];
                    if(j < n-1) right += dp[i][j+1];
                    else right += 1e9;

                    dp[i][j] = min(down, right);
                }
            }
        }

        return dp[0][0];
    }

    int minPathSum(vector<vector<int>>& grid) {
        // return solveUsingRec(grid, 0, 0);

        // int m = grid.size(), n = grid[0].size();
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return solveUsingMem(grid, 0, 0, dp);

        return solveUsingTab(grid);
    }
};