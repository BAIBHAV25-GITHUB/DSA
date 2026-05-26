class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        for(int r = 0; r < nums.size(); r++){
            sort(nums[r].begin(), nums[r]. end());
        }

        int score = 0;
        for(int c = 0; c < nums[0].size(); c++){
            int maxi = 0;
            for(int r = 0; r < nums.size(); r++){
                maxi = max(maxi, nums[r][c]);
            }
            score += maxi;
        }
        return score;
    }
};