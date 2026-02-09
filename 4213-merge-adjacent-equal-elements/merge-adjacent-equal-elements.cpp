class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> st;
        for(long long x: nums){
            st.push_back(x);
            while(st.size() >= 2 && st.back() == st[st.size()-2]){
                long long num = st.back();
                st.pop_back();
                st.pop_back();
                st.push_back(num+num);
            } 
        }
        return st;
    }
};