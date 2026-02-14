class Solution {
public:
    vector<int> original;
    vector<int> arr;

    Solution(vector<int>& nums) {
        original = nums;
        arr = nums;    
    }
    
    vector<int> reset() {
        arr = original;
        return arr;
    }
    
    vector<int> shuffle() {
        // vector<int> temp = original;
        // vector<int> ans;
        // while(!temp.empty()){
        //     int idx = rand() % temp.size();
        //     ans.push_back(temp[idx]);
        //     temp.erase(temp.begin()+idx);
        // }
        // return ans;

        for(int i=arr.size()-1; i>0; i--){
            int j=rand()%(i+1);
            swap(arr[i], arr[j]);
        }
        return arr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */