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

    // int solveUsingMem(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& dp){
    //     if(row == matrix.size()){
    //         return 0;
    //     }
    //     if(dp[row][col] != INT_MIN){
    //         return dp[row][col];
    //     }
    //     int sum = matrix[row][col] + solveUsingMem(matrix, row+1, col, dp);

    //     if(row+1 < matrix.size() && col-1 >= 0){
    //         sum = min(sum, matrix[row][col]+solveUsingMem(matrix, row+1, col-1, dp));
    //     }
    //     if(row+1 < matrix.size() && col+1 < matrix.size()){
    //         sum = min(sum, matrix[row][col]+solveUsingMem(matrix, row+1, col+1, dp));
    //     }

    //     return dp[row][col] = sum;
    // }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        // int res = INT_MAX;
        // for(int col=0; col<matrix.size(); col++){
        //     res = min(res, solveUsingRec(matrix, 0, col));
        // }
        // return res;

        // int n=matrix.size();
        // vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        // int res = INT_MAX;
        // for(int col=0; col<matrix.size(); col++){
        //     res = min(res, solveUsingMem(matrix, 0, col, dp));
        // }
        // return res;

        int n=matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for(int col=0; col<n; col++){
            dp[0][col] = matrix[0][col];
        } 

        for(int row=1; row<n; row++){
            for(int col=0; col<n; col++){
                int a=INT_MAX;
                int b=INT_MAX;
                if(col-1>=0) a = dp[row-1][col-1];
                if(col+1<n) b = dp[row-1][col+1];

                dp[row][col] = matrix[row][col] + min({dp[row-1][col], a, b});
            }
        }

        int res=INT_MAX;
        for(int col=0; col<n; col++){
            res = min(res, dp[n-1][col]);
        }
        return res;
    }
};