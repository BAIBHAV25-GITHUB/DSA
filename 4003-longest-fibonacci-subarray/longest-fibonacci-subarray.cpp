class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n =nums.size();
        if(n == 1 || n == 2) return n;

        int i=0, j=1;
        int count = 0, maxi = INT_MIN;
        while(i < j && j < n-1){
            int sum = nums[i]+nums[j];
            if(j+1 < n && sum == nums[j+1]){
                count++;
            }    
            else count = 0;
            maxi = max(maxi, count);
            i = j;
            j = j+1;
        }
        return maxi+2;
    }
};