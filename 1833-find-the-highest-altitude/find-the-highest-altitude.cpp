class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum = 0, highest = 0;
        for(int g:gain){
            sum += g; 
            highest = max(highest, sum);
        }
        return highest;
    }
};