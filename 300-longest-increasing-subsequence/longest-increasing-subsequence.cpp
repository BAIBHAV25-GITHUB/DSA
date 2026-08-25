class Solution {
public:
    // int solveUsingMem(vector<int>& nums, int curr, int prev, vector<vector<int>>& dp){
    //     if(curr >= nums.size()) return 0;
    //     if(dp[curr][prev+1] != -1) return dp[curr][prev+1]; 

    //     int include = 0;
    //     if(prev == -1 || nums[curr] > nums[prev]){
    //         include = 1+solveUsingMem(nums, curr+1, curr, dp);
    //     }
    //     int exclude = 0+solveUsingMem(nums, curr+1, prev, dp);
    //     dp[curr][prev+1] = max(include, exclude);
    //     return dp[curr][prev+1];
    // }

    int solveUsingTab(vector<int>& nums){
        int n=nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int curr=n-1; curr>=0; curr--){
            for(int prev=curr-1; prev>= -1; prev--){
                int include = 0;
                if(prev == -1 || nums[curr] > nums[prev]){
                    include = 1+dp[curr+1][curr+1];
                }
                int exclude = dp[curr+1][prev+1];
                dp[curr][prev + 1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // int prev=-1, curr=0;
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        
        // return solveUsingMem(nums,0, -1, dp);

        return solveUsingTab(nums);
    }
};