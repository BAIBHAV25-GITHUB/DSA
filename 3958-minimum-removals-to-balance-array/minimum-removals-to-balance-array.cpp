class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int l = 0, ans = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for(int r=0; r<n; r++){
            while((long long)nums[l]*k < nums[r]) l++;

            ans = max(ans, r-l+1);
        }
        return n-ans;
    }
};