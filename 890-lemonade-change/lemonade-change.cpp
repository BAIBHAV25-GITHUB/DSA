class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveDollar = 0, tenDollar = 0;
        for(int i : bills){
            if(i == 5){
                fiveDollar += 1;
            }
            else if(i == 10){
                if(fiveDollar > 0){
                    fiveDollar -= 1;
                    tenDollar += 1;
                }
                else return false;
            }
            else{
                if(fiveDollar > 0 && tenDollar > 0){
                    fiveDollar -= 1;
                    tenDollar -= 1;

                }
                else if(fiveDollar >= 3){
                    fiveDollar -= 3;
                }
                else return false;
            }
        }
        return true;
    }
};