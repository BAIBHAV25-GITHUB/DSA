class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0;
        for(char c:s){
            if(c == '*'){
                len = max((long long) 0, len-1);
            }
            else if(c == '#'){
                len *= 2;
            }
            else if(c != '%'){
                len++;
            }
        }

        if(k >= len) return '.';

        for(int i=s.size()-1; i>=0; i--){
            char c=s[i];

            if(c == '*'){
                len++;
            }
            else if(c == '#'){
                long long half = len/2;
                if(k >= half){
                    k -= half;
                }
                len = half;
            }
            else if(c == '%'){
                k=len-k-1;
            }
            else{
                if(k == len-1){
                    return c;
                }
                len--;
            }
        }
        return '.';
    }
};