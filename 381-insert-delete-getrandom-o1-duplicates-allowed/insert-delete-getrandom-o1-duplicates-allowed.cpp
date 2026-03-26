class RandomizedCollection {
public:
    vector<int> nums;
    unordered_map<int, unordered_set<int>> mp;

    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        nums.push_back(val);
        mp[val].insert(nums.size() - 1);
        return mp[val].size() == 1;
    }
    
    bool remove(int val) {
        if(mp[val].empty()) return false;

        int removeIdx = *mp[val].begin();
        mp[val].erase(removeIdx);

        int lastVal = nums.back();
        nums[removeIdx] = lastVal;

        // Update map for last element
        mp[lastVal].insert(removeIdx);
        mp[lastVal].erase(nums.size() - 1);

        nums.pop_back();

        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */