class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        // vector<int> ans;
        // for(int x : nums)
        //     if(x < pivot) ans.push_back(x);
        // for(int x : nums)
        //     if(x == pivot) ans.push_back(pivot);
        // for(int x : nums)
        //     if(x > pivot) ans.push_back(x);
    
        // return ans;

        int n = nums.size();
        vector<int> ans(n);
        int l=0, r=n-1;
        for(int i=0; i<n; i++){
            if(nums[i] < pivot) ans[l++] = nums[i];
        }

        for(int i=nums.size()-1; i>=0; i--){
            if(nums[i] > pivot) ans[r--] = nums[i];
        }

        while(l <= r) ans[l++] = pivot;

        return ans;
    }
};