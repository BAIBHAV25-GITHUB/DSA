class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> numFreq;
        unordered_map<int, int> freqCnt;

        for(auto it : nums){
            numFreq[it]++;
        }

        for(auto it : numFreq){
            freqCnt[it.second]++;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (freqCnt[numFreq[nums[i]]] == 1)
                return nums[i];
        }
        return -1;
    }
};