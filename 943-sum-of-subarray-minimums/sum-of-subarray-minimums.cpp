class Solution {
public:
    vector<int> nextSmaller(vector<int> &arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        
        for(int i = n - 1; i >= 0; i--) {
            int currEle = arr[i];
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        return ans;
    }
    
    vector<int> prevSmaller(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        
        for(int i=0; i < n; i++) {
            int currEle = arr[i];
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = nextSmaller(arr);
        
        vector<int> pse = prevSmaller(arr);
        int n = arr.size(), sum = 0;
        int MOD = 1e9 + 7;
        
        for(int i=0; i < n; i++) {
            // Count of first type of subarrays
            int left = i - pse[i];
            
            // Count of second type of subarrays
            int right = nse[i] - i;
            
            /* Count of subarrays where 
            current element is minimum */
            long long freq = left*right*1LL;
            
            // Contribution due to current element 
            int val = (freq*arr[i]*1LL) % MOD;
            sum = (sum + val) % MOD;
        }
        return sum;
    }
};