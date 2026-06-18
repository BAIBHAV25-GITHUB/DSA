class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n=0, m=0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '#'){
                n--;
                n=max(0, n);
            }
            else{
                s[n]=s[i];
                n++;
            }
        }

        for(int i=0; i<t.size(); i++){
            if(t[i] == '#'){
                m--;
                m=max(0, m);
            }
            else{
                t[m]=t[i];
                m++;
            }
        }

        if(n != m) return false;
        else{
            for(int i=0; i<n; i++){
                if(s[i] != t[i]) return false;
            }
            return true;
        }
    }
};