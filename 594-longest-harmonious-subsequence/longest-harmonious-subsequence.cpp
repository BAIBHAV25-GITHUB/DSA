class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int num : nums){
            mp[num]++;
        }

        int maxLen = 0;

        for(auto it : mp){
            if(mp.count(it.first + 1)){
                int currLen = it.second + mp[it.first + 1];
                maxLen = max(maxLen, currLen);
            }
        }

        return maxLen;
    }
};