class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int res = 0, cnt = 0;
        for(int i=2; i<nums.size(); i++){
            if(nums[i]-nums[i-1] == nums[i-1]-nums[i-2]){
                cnt += 1;
            }
            else{
                res += (cnt * (cnt+1))/2;
                cnt=0;
            }
        }
        return res += (cnt * (cnt+1))/2;;
    }
};