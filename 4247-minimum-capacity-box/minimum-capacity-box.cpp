class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int minIdx = -1, last = 101;
        for(int i = 0; i < capacity.size(); i++){
            int val = capacity[i];
            if(val >= itemSize){
                if(val < last){
                    last = val;
                    minIdx = i;
                }
            }
        }
        return minIdx;
    }
};