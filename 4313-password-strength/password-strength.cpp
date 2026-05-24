class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char> st;
        int strength = 0;

        for(auto it : password){
            st.insert(it);
        }

        for(auto& it : st){
            char c = it;
            if(c >= 'a' && c <= 'z'){
                strength += 1;
            }
            else if(c >= 'A' && c <= 'Z'){
                strength += 2;
            }
            else if(c-'0' >= 0 && c-'0' <= 9){
                strength += 3;
            }
            else{
                strength += 5;
            }
        }

        return strength;
    }
};