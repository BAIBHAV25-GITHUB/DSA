class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char, int>> arr(123);
        for(char c: s){
            int freq = arr[c].second;
            arr[c] = {c, freq+1};
        }

        sort(arr.begin(), arr.end(),
            [](pair<char,int>& a, pair<char,int>& b) {
                return a.second > b.second;
            });

        string ans="";
        for(auto& p:arr){
            ans.append(p.second, p.first);
        }
        return ans;
    }
};