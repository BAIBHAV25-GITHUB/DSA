class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;
        for(int i = nums.size()-1; i >= 0; i--){
            int x = nums[i];
            while(x > 0){
                result.push_back(x%10);
                x = x / 10;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};