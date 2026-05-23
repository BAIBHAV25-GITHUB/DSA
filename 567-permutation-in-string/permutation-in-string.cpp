class Solution {
public:
    bool areEqual(vector<int> a, vector<int> b){
        for(int i = 0; i < 26; i++){
            if(a[i] != b[i]) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) return false;

        int i = 0, j = 0;

        vector<int> S1(26, 0);
        for(char c : s1) S1[c - 'a']++;

        vector<int> S2(26, 0);
        while(j < s2.size()){
            S2[s2[j] - 'a']++;

            if(j-i+1 == s1.size()){
                if(areEqual(S1, S2)) return true;
            }

            if(j-i+1 >= s1.size()){
                S2[s2[i] - 'a']--;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return false;
    }
};