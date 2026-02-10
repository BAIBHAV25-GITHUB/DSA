class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        int ans=0;

        for(int i=0; i<n; i++){
            unordered_set<int> st;
            int count[2] = {0, 0};
            for(int j=i; j<n; j++){
                if(!st.count(nums[j])){
                    st.insert(nums[j]);
                    count[nums[j] % 2]++;
                }
                
                if(count[0] == count[1]){
                    ans = max(ans, j-i+1);
                }
            }
        }
        return ans;
    }
};