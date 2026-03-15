class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long ans = 1;
        long long curr = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i-1]){
                curr++;
            }
            else curr = 1;
            ans += curr;
        }
        return ans;
    }
};