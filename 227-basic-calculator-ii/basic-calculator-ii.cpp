class Solution {
public:
    int calculate(string s) {
        int len = s.size();
        if(len == 0) return 0;
        char op = '+';
        stack<int> st;
        int currNum = 0;
        for(int i=0; i<len; i++){
            char currChar = s[i];
            if(isdigit(currChar)){
                currNum = (currNum * 10) + (currChar - '0');
            }
            if(!isdigit(currChar) && !iswspace(currChar) || i == len-1){
                if(op == '+') st.push(currNum);
                else if(op == '-') st.push(-currNum);
                else if(op == '*'){
                    int top_el = st.top();
                    st.pop();
                    st.push(top_el * currNum);
                }
                else if(op == '/'){
                    int top_el = st.top();
                    st.pop();
                    st.push(top_el / currNum);
                }
                op = currChar;
                currNum = 0;
            }
        }

        int res = 0;
        while(st.size()){
            res += st.top();
            st.pop();
        }
        return res;

    }
};