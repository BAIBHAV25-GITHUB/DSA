class Solution {
public:
    int calPoints(vector<string>& operations) {
        int ans = 0;
        stack<int> st;
        for(int i=0; i<operations.size(); i++){
            if(operations[i] == "+"){
                int last = st.top();
                st.pop();
                int slast = st.top();
                st.push(last);
                st.push(last + slast);
                
            }
            else if(operations[i] == "C"){
                st.pop();
            }
            else if(operations[i] == "D"){
                st.push(2*st.top());
            }
            else{
                st.push(stoi(operations[i]));
            }
        }

        while(st.size()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};