class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int x=lower;

        for(int n:nums){
            if(n<lower || n>upper) continue;

            if(n>x) res.push_back({x, n-1});

            x=n+1;
        }

        if(x <= upper) res.push_back({x, upper});
        return res;
    }
};