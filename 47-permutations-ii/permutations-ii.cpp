class Solution {
public:
    void solve(vector<int>& nums, int i, int n, vector<vector<int>>& res){
        if(i == n){
            res.push_back(nums);
            return;
        }
        unordered_set<int> used;

        for(int j=i; j<=n; j++){
            if (used.count(nums[j])) continue;
            used.insert(nums[j]);
            swap(nums[i], nums[j]);
            solve(nums, i+1, n, res);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size()-1;
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        solve(nums, 0, n, res);
        return res;
    }
};