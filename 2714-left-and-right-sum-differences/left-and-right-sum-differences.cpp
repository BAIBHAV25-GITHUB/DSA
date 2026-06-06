class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int lSum =0, rSum = 0;
        for(int i = 0; i <= n-1; i++){
            ans[i] = lSum;
            lSum += nums[i];
        }

        for(int i = n-1; i >= 0; i--){
            ans[i] = abs(ans[i] - rSum);
            rSum += nums[i];
        }
        return ans;
    }
};