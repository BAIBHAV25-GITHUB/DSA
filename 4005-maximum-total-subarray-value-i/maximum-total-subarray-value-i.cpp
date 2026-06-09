class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxi = INT_MIN, mini = INT_MAX;
        for(long long x : nums){
            maxi = max(maxi, x);
            mini = min(mini, x);
        }

        return (maxi - mini) * k * 1LL;
    }
};