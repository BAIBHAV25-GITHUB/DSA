class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> index(n);
        for(int i = 0; i < n; i++){
            index[i] = i;
        }

        sort(index.begin(), index.end(), [&](int a, int b){
            return positions[a] < positions[b];
        });

        stack<int> st;
        for(int i : index){
            if(directions[i] == 'R'){
                st.push(i);
            }
            else{
                while(!st.empty() && healths[i] > 0){
                    int j = st.top();
                    st.pop();

                    if(healths[j] > healths[i]){
                        healths[j]--;
                        healths[i] = 0;
                        st.push(j);
                    }
                    else if(healths[i] > healths[j]){
                        healths[i]--;
                        healths[j] = 0;
                    }
                    else{
                        healths[i] = 0;
                        healths[j] = 0;
                    }
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++){
            if(healths[i] > 0) ans.push_back(healths[i]);
        }

        return ans;
    }
};