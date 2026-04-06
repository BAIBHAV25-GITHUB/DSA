class Solution {
public:
    bool judgeCircle(string moves) {
        int countx = 0, county = 0;
        for(int i = 0; i < moves.size(); i++){
            if(moves[i] == 'L') countx++;
            else if(moves[i] == 'R') countx--;
            else if(moves[i] == 'U') county++;
            else county--;
        }
        return countx == 0 && county == 0;
    }
};