class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int freq[26] = {0};
        for(char c:text){
            freq[c-'a']++;
        }
        return min({freq[0], freq[1], freq[11]>>1, freq[14]>>1, freq[13]});
    }
};