class Solution {
public:
    vector<int> findNSE(vector<int>& nums){
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();

            ans[i] = !st.empty() ? st.top() : n;

            st.push(i);
        }
        
        return ans;
    }

    vector<int> findNGE(vector<int>& nums){
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();

            ans[i] = !st.empty() ? st.top() : n;

            st.push(i);
        }
        
        return ans;
    }

    vector<int> findPSE(vector<int>& nums){
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] > nums[i]) st.pop();

            ans[i] = !st.empty() ? st.top() : -1;

            st.push(i);
        }
        
        return ans;
    }

    vector<int> findPGE(vector<int>& nums){
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] < nums[i]) st.pop();

            ans[i] = !st.empty() ? st.top() : -1;

            st.push(i);
        }
        
        return ans;
    }

    long long sumSubarrayMins(vector<int> &nums) {
        vector<int> nse = findNSE(nums);
        vector<int> psee = findPSE(nums);
        int n = nums.size();
        long long sum = 0;
        for(int i=0; i < n; i++) {
            int left = i - psee[i];
            int right = nse[i] - i;
            
            long long freq = left*right*1LL;
            long long val = (freq*nums[i]*1LL);
            
            sum += val;
        }
        return sum;
    }
    
    long long sumSubarrayMaxs(vector<int> &nums) {
        vector<int> nge = findNGE(nums);
        vector<int> pgee = findPGE(nums);
        int n = nums.size();
        long long sum = 0;
        for(int i=0; i < n; i++) {
            int left = i - pgee[i];
            int right = nge[i] - i;
            
            long long freq = left*right*1LL;
            long long val = (freq*nums[i]*1LL);
            
            sum += val;
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        return (sumSubarrayMaxs(nums) -  sumSubarrayMins(nums));
    }
};