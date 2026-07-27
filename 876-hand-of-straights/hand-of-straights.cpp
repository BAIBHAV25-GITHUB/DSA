class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;

        unordered_map<int, int> mp;
        for(int h:hand){
            mp[h]++;
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto& it:mp){
            pq.push(it.first);
        }

        while(!pq.empty()){
            int start = pq.top();
            for(int i=0; i<groupSize; i++){
                int curr = start+i;
                
                if(mp[curr] == 0){
                    return false;
                }

                mp[curr]--;

                if(mp[curr] == 0){
                    if(curr != pq.top()){
                        return false;
                    }
                    pq.pop();
                }
            }
        }
        return true;
    }
};