class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26, 0);
        for(auto& task : tasks){
            mp[task - 'A']++;        
        }

        sort(mp.begin(), mp.end());
        int maxi = mp[25];
        int idle = maxi - 1;
        int idleSlot = n * idle;

        for(int i = 24; i >=0; i--){
            idleSlot -= min(mp[i], idle);
        }

        if(idleSlot > 0) return tasks.size() + idleSlot;

        return tasks.size();
    }
};