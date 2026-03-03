class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for(char c:s){
            if(c != ']') st.push(c);
            else{
                string decode = "";
                while(!st.empty() && st.top() != '['){
                    decode = st.top()+decode;
                    st.pop();
                }
                st.pop();
                string numStr = "";
                while(!st.empty() && isdigit(st.top())){
                    numStr = st.top()+numStr;
                    st.pop();
                }
                int num = stoi(numStr);
                while(num--){
                    for(char c:decode){
                        st.push(c);
                    }
                }
            }
        }
        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};