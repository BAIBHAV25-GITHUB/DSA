class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int totalShifts = 0;
        for(int i = shifts.size() -1; i >= 0; i--){
            totalShifts = (totalShifts + shifts[i]) % 26;
            s[i] = (s[i] - 'a' + totalShifts) % 26 + 'a';
        }
        return s;
    }
};