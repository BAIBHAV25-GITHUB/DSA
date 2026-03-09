class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int currSum = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            currSum += (nums[i] == 1) ? 1 : -1;

            if(mp.find(currSum) != mp.end()) res = max(res, i-mp[currSum]);
            else mp[currSum] = i;
        } 
        return res;
    }
};