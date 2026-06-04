class Solution {
public:
    int findScore(int n){
        string s = to_string(n);
        int l = s.length();
        int score = 0;

        if(l < 3) return 0;
        for(int i = 1; i <= l-2; i++){
            if(s[i] > s[i-1] && s[i] > s[i+1]) score++;
            if(s[i] < s[i-1] && s[i] < s[i+1]) score++;
        }
        return score;
    }
    int totalWaviness(int num1, int num2) {
        int score = 0;
        for(int i = num1; i <= num2;  i++){
            score += findScore(i);
        }
        return score;
    }
};