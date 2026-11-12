class Solution {
public:
    // int solveUsingRec(vector<vector<int>>& matrix, int row, int col){
    //     if(row == matrix.size()){
    //         return 0;
    //     }

    //     int sum = matrix[row][col] + solveUsingRec(matrix, row+1, col);

    //     if(row+1 < matrix.size() && col-1 >= 0){
    //         sum = min(sum, matrix[row][col]+solveUsingRec(matrix, row+1, col-1));
    //     }
    //     if(row+1 < matrix.size() && col+1 < matrix.size()){
    //         sum = min(sum, matrix[row][col]+solveUsingRec(matrix, row+1, col+1));
    //     }

    //     return sum;
    // }

    int solveUsingMem(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& dp){
        if(row == matrix.size()){
            return 0;
        }
        if(dp[row][col] != INT_MIN){
            return dp[row][col];
        }
        int sum = matrix[row][col] + solveUsingMem(matrix, row+1, col, dp);

        if(row+1 < matrix.size() && col-1 >= 0){
            sum = min(sum, matrix[row][col]+solveUsingMem(matrix, row+1, col-1, dp));
        }
        if(row+1 < matrix.size() && col+1 < matrix.size()){
            sum = min(sum, matrix[row][col]+solveUsingMem(matrix, row+1, col+1, dp));
        }

        return dp[row][col] = sum;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        // int res = 1e9;
        // for(int col=0; col<matrix.size(); col++){
        //     res = min(res, solveUsingRec(matrix, 0, col));
        // }
        // return res;

        int n=matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        int res = 1e9;
        for(int col=0; col<matrix.size(); col++){
            res = min(res, solveUsingMem(matrix, 0, col, dp));
        }
        return res;
    }
};