class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for (int i = x, j = x + k - 1; i < j; i++, j--) {
            for (int l = y; l < y + k; l++) {
                swap(grid[i][l], grid[j][l]);
            }
        }
        return grid;
    }
};