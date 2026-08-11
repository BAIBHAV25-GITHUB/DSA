class Solution {
public:
    int rob(vector<int>& nums) {
        // Tabulation Method
        // int n = nums.size();

        // if(n == 1) return nums[0];

        // vector<int> dp(n, -1);
        // dp[0] = nums[0];
        // dp[1] = max(nums[0], nums[1]);
        // for(int i=2; i<n; i++){
        //     dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        // }
        // return dp[n-1];

        // Space Optimized
        int prev1 = 0, prev2 = 0, curr;
        for(int i=0; i<nums.size(); i++){
            curr = max(prev1, prev2+nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};