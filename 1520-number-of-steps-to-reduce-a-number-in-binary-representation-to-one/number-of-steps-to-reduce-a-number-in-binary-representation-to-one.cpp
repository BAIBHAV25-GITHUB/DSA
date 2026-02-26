class Solution {
public:
    // void plusOne(string& s){
    //     int i = s.size()-1;
    //     while(i >= 0 && s[i] != '0'){
    //         s[i] = '0';
    //         i--;
    //     }
    //     if(i < 0){
    //         s = '1' + s;
    //     }
    //     else s[i] = '1';
    // }
    // int numSteps(string s) {
    //     int ops = 0;
    //     while(s.size() > 1){
    //         int n = s.size();
    //         if(s[n-1] == '0') s.pop_back();
    //         else{
    //             plusOne(s);
    //         }
    //         ops++;
    //     }
    //     return ops;
    // }

    int numSteps(string s){
        int n = s.size(), ops = 0, carry = 0;
        for(int i = n-1; i >= 1; i--){
            if(((s[i] - '0') + carry) % 2 == 1){
                ops += 2;
                carry = 1;
            }
            else ops += 1;
        }
        return ops + carry;
    }
};