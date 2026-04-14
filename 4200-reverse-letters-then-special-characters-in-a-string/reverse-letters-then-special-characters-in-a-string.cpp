class Solution {
public:
    string reverseByType(string s) {
        string letters = "", special = "";
        string ans = "";
        for(char c : s){
            if(isalpha(c)) letters += c;
            else special += c;
        }

        int i = letters.size()-1;
        int j = special.size()-1;

        for(int k = 0; k < s.size(); k++){
            if(isalpha(s[k])) ans += letters[i--];
            else ans += special[j--]; 
        }

        return ans;
    }
};