class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        for(auto val : grid){
            for(auto n : val){
                nums.push_back(n);
            }
        }

        int rem = nums[0] % x;
        for(auto n : nums){
            if(n % x != rem) return -1;
        }

        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];

        int ans = 0;
        for(auto n : nums){
            ans += abs(n - median)/x;
        }

        return ans;
    }
};