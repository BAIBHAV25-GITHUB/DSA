class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> freq(n+1, 0);

        for(int c : citations){
            if(c >= n) freq[n] += 1;
            else freq[c] += 1;
        }

        int idx = n;
        int s = freq[n];
        while(s < idx){
            idx -= 1;
            s += freq[idx];
        }
        return idx;
    }
};