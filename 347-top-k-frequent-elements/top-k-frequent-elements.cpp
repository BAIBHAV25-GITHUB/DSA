class Solution {
public:
    typedef pair<int, int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int n:nums){
            mp[n]++;
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        for(auto& it:mp){
            int num = it.first;
            int freq = it.second;
            pq.push({freq, num});
            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};