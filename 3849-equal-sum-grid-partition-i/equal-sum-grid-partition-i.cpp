class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        long long totalSum = 0;
        vector<long long> rowSum(m, 0);
        vector<long long> colSum(n, 0);
        for(int i =0; i < m; i++){
            for(int j = 0; j < n; j++){
                totalSum += grid[i][j];
                rowSum[i] += grid[i][j];
                colSum[j] += grid[i][j];
            }
        }

        // for odd sum no split possible
        if(totalSum % 2) return false;

        // horizontal split
        long long h = 0;
        for(int i = 0; i < m; i++){
            h += rowSum[i];
            if(h == totalSum - h) return true;
        }

        //  vertical split
        long long v = 0;
        for(int j = 0; j < n; j++){
            v += colSum[j];
            if(v == totalSum - v) return true;
        }

        return false;
    }
};