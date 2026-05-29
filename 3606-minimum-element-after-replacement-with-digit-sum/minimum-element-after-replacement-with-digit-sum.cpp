class Solution {
public:
    int sumDigit(int n){
        int x = n;
        int sum = 0;
        while(x > 0){
            sum += x % 10;
            x = x/10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int mini = INT_MAX;
        int x = 0;
        for(int i = 0; i < nums.size(); i++){
            x = sumDigit(nums[i]);
            mini = min(mini, x);
        }
        return mini;
    }
};