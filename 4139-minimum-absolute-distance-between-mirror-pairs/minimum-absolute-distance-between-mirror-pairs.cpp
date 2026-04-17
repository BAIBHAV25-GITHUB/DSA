class Solution {
public:
    int reverseNum(int x){
        int ans = 0;
        while(x > 0){
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size(), ans = 1e6;
        for(int i = 0; i < n; i++){
            if(mp.count(nums[i])){
                ans = min(ans, i - mp[nums[i]]);
            }
            mp[reverseNum(nums[i])] = i;
        }
        return ans == 1e6? -1 : ans;
    }
};