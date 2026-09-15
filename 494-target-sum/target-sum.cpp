class Solution {
public:
    int solveUsingRec(vector<int>& nums, int target, int idx, int sum){
        if(idx == nums.size()){
            if(sum == target) return 1;
            return 0;
        }

        int add = solveUsingRec(nums, target, idx+1, sum+nums[idx]);
        int sub = solveUsingRec(nums, target, idx+1, sum-nums[idx]);

        return add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solveUsingRec(nums, target, 0, 0);
    }
};