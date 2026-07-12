class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int, int> mp;
        vector<int> rank(arr);
        sort(rank.begin(), rank.end());

        int r =1;
        for(int i=0; i<rank.size(); i++){
            if(i > 0 && rank[i]>rank[i-1]){
                r++;
            }
            mp[rank[i]] = r;
        }
        for(int i=0; i<arr.size(); i++){
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};