class Solution {
public:
    // bool solveUsingRec(vector<int>& nums, int target, int index, int n){
    //     if(index >= n) return false;
    //     if(target < 0) return false;

    //     if(target == 0) return true;

    //     bool include =solveUsingRec(nums, target-nums[index], index+1, n);
    //     bool exclude =solveUsingRec(nums, target, index+1, n);

    //     return(include || exclude);
    // }

    // bool solveUsingMem(vector<int>& nums, int target, int index, int n, vector<vector<int>>& dp){
    //     if(index >= n) return false;
    //     if(target < 0) return false;

    //     if(target == 0) return true;

    //     if(dp[index][target] != -1) return dp[index][target];

        // bool include = solveUsingMem(nums, target-nums[index], index+1, n, dp);
        // bool exclude = solveUsingMem(nums, target, index+1, n, dp);

        // dp[index][target] = (include || exclude);
        // return dp[index][target];
    // }

    bool solveUsingTab(vector<int>& nums, int target){
        int n=nums.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));


        for(int i=0; i<n; i++){
            dp[i][0]= 1;
        }

        for(int i=n-1; i>=0; i--){
            for(int t=1; t<=target; t++){
                bool include = 0;
                if(t-nums[i] >= 0) include = dp[i+1][t-nums[i]];
                bool exclude = dp[i+1][t];

                dp[i][t] = (include || exclude);
            }
        }

        return dp[0][target];
    }

    bool canPartition(vector<int>& nums) {
        int n=nums.size(), sum=0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        if(sum & 1) return false;

        int target = sum/2;

        // vector<vector<int>> dp(n, vector<int>(target+1, -1));
        // return solveUsingMem(nums, target, 0, n, dp);

        return solveUsingTab(nums, target);
    }
};