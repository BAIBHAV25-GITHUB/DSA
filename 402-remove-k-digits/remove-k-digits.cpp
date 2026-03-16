class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() == k) return "0";
        string stack = "";
        for(int i = 0; i < num.size(); i++){
            while(k > 0 && !stack.empty() && stack.back() > num[i]){
                stack.pop_back();
                k--;
            }
            stack.push_back(num[i]);
        }

        while(k > 0){
            stack.pop_back();
            k--;
        }

        string ans = "";
        bool flag = true;
        for(char c : stack){
            if(flag && c == '0') continue;
            flag = false;
            ans += c;
        }
        return (ans == "") ? "0" : ans;
    }
};