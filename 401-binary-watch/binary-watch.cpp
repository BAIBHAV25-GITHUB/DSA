class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for(int HH=0; HH <= 11; HH++){
            for(int MH=0; MH <= 59; MH++){
                if(__builtin_popcount(HH) + __builtin_popcount(MH) == turnedOn){
                    string hour = to_string(HH);
                    string minute = (MH < 10 ? "0" : "") + to_string(MH);
                    ans.push_back(hour + ":" + minute);
                }
            }
        }
        return ans;
    }
};