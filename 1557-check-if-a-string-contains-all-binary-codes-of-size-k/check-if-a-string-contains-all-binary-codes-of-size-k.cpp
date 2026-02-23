class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int code = 1 << k;
        string sub;
        unordered_set<string> st;
        for(int i=k; i<=s.length(); i++){
            sub = s.substr(i-k, k);
            if(!st.count(sub)){
                st.insert(sub);
                code--;
            }
            if(code == 0) return true;
        }
        return false;
    }
};