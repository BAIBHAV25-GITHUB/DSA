class Solution {
public:
    int t[101]; 
    int maxAmount(vector<int>& nums, int index){
        if (index >= nums.size()){
            return 0;
        }

        if(t[index] != -1) return t[index];

        int amount1=nums[index]+maxAmount(nums, index+2);
        int amount2=maxAmount(nums,index+1);

        return t[index] = max(amount1, amount2);

    } 
    int rob(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        return maxAmount(nums, 0);
    }
};