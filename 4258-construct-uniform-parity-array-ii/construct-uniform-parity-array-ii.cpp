class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini = nums1[0], odd = 0;

        for(int x:nums1){
            mini = min(mini, x);
            if(x%2 == 1) odd++;
        }

        return (mini % 2) || odd == 0;
    }
};