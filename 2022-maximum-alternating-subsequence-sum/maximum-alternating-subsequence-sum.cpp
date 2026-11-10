class Solution {
public:
    // long long solveUsingRec(int idx, vector<int>& nums, bool flag){
    //     if(idx >= nums.size()) return 0;

    //     int skip = solveUsingRec(idx+1, nums, flag);
    //     int val = nums[idx];
    //     if(!flag) val = -val;

    //     int take = val + solveUsingRec(idx+1, nums, !flag);
    //     return max(take, skip); 
    // }

    long long solveUsingMem(int idx, vector<int>& nums, bool flag, vector<vector<long long>>& dp){
        if(idx >= nums.size()) return 0;
        if(dp[idx][flag] != -1) return dp[idx][flag];

        long long skip = solveUsingMem(idx+1, nums, flag, dp);
        int val = nums[idx];
        if(!flag) val = -val;

        long long take = val + solveUsingMem(idx+1, nums, !flag, dp);
        return dp[idx][flag] = max(take, skip); 
    }

    long long maxAlternatingSum(vector<int>& nums) {
        // return solveUsingRec(0, nums, true);

        int n=nums.size();
        vector<vector<long long>> dp(n+1, vector<long long>(2, -1));
        return solveUsingMem(0, nums, true, dp);
    }
};