class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Greedy 
        // vector<int> mp(26, 0);
        // for(auto& task : tasks){
        //     mp[task - 'A']++;        
        // }

        // sort(mp.begin(), mp.end());
        // int maxi = mp[25];
        // int idle = maxi - 1;
        // int idleSlot = n * idle;

        // for(int i = 24; i >=0; i--){
        //     idleSlot -= min(mp[i], idle);
        // }

        // if(idleSlot > 0) return tasks.size() + idleSlot;

        // return tasks.size();

        
        //Using Heap
        vector<int> mp(26, 0);
        for(char& ch:tasks){
            mp[ch-'A']++;
        }

        int time = 0;
        priority_queue<int> pq;
        for(int i=0; i<26; i++){
            if(mp[i] > 0){
                pq.push(mp[i]);
            }
        }

        while(!pq.empty()){
            vector<int> temp;
            for(int i=1; i<= n+1; i++){
                if(!pq.empty()){
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }

            for(int& t:temp){
                if(t>0){
                    pq.push(t);
                }
            }

            if(pq.empty()){
                time += temp.size();
            }
            else{
                time += n+1;
            }
        }

        return time;
    }
};