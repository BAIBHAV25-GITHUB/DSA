class Solution {
public:
    string maximumXor(string s, string t) {
        int zero = 0, one = 0;
        for(char c : t){
            if(c == '0') zero++;
            else one++;
        } 

        string ans = "";
        for(int i=0; i<s.size(); i++){
            if(s[i] == '1'){
                if(zero){
                    ans += '1';
                    zero--;
                }
                else{
                    ans += '0';
                    one--; 
                }               
            }
            else{
                if(one){
                    ans += '1';
                    one--;
                }
                else{
                    ans += '0';
                    zero--;
                }
            }
        }
        return ans;
    }
};