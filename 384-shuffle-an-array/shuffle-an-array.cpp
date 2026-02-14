class Solution {
public:
    vector<int> original;

    Solution(vector<int>& nums) {
        original = nums;    
    }
    
    vector<int> reset() {
        return original;
    }
    
    vector<int> shuffle() {
        vector<int> temp = original;
        vector<int> ans;
        while(!temp.empty()){
            int idx = rand() % temp.size();
            ans.push_back(temp[idx]);
            temp.erase(temp.begin()+idx);
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */