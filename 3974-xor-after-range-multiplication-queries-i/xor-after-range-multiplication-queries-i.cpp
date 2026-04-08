class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int mod = 1e9 + 7;
        for(auto &it:queries){
            int l = it[0], r = it[1], k = it[2], v = it[3];
            int idx = l;
            while(idx <= r){
                long long temp = nums[idx];
                nums[idx] = (temp * v) % mod;
                idx += k;
            }
        }
        int ans=0;
        for(int n : nums){
            ans ^= n;
        }
        return ans;
    }
};