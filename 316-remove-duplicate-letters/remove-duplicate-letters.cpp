class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(128, 0);
        vector<bool> used(160, false);
        string ans;

        for(char c:s){
            count[c]++;
        }

        for(char c:s){
            count[c]--;
            if(used[c]) continue;
            while(!ans.empty() && ans.back() > c && count[ans.back()] > 0){
                used[ans.back()] = false;
                ans.pop_back();
            }
            ans.push_back(c);
            used[c] = true; 
        }
        return ans;
    }
};