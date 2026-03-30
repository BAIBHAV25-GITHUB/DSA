class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int len = s1.size();
        if (len != s2.size()) {
            return false;
        }

        int freq[52] = {0};

        for (int i = 0; i < len; i++) {
            int val = (i & 1) * 26;
            freq[val + s1[i] - 'a']++;
            freq[val + s2[i] - 'a']--;
        }

        for (int i = 0; i < 52; i++) {
            if (freq[i] != 0) return false;
        }
    
        return true;
    }
};