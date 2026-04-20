class Solution {
public:
    bool checkValidString(string s) {
        int minCnt = 0, maxCnt = 0;
        for(char c : s){
            if(c == '('){
                minCnt++;
                maxCnt++;
            }
            else if(c == ')'){
                minCnt--;
                maxCnt--;
            }
            else{
                minCnt--;
                maxCnt++;
            }

            if(maxCnt < 0) return false;

            minCnt = max(minCnt, 0);
        }
        return minCnt == 0;
    }
};