class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        // Brute Force - T(n):O(nlogn)
        // sort(nums.begin(), nums.end());
        // int n = nums.size();

        // return (nums[n-1] * nums[n-2]) - (nums[0] * nums[1]);

        // Optimal - T(n):O(n)
        int mini1 = INT_MAX, mini2 = INT_MAX;
        int maxi1 = 0, maxi2 = 0;

        for(int num:nums){
            if(num > maxi1){
                maxi2 = maxi1;
                maxi1 = num;
            }
            else if(num > maxi2){
                maxi2 = num;
            }

            if(num < mini1){
                mini2 = mini1;
                mini1 = num;
            }
            else if(num < mini2){
                mini2 = num;
            }
        }
        return (maxi1*maxi2) - (mini1*mini2);
    }
};