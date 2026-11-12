class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int up=1, down=1, maxi=1;
        for(int i=1; i<nums.size(); i++){
            up = (nums[i-1] < nums[i])? up+1:1;
            down = (nums[i-1] > nums[i])? down+1:1;
            maxi = max(maxi, max(up, down));
        }
        return maxi;
    }
};