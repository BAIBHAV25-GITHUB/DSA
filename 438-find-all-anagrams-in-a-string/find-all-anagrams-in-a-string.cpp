class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        vector<int> count(26, 0);
        if(s.size() < p.size()) return res;

        // string sortedP = p;
        // sort(sortedP.begin(), sortedP.end());

        // for(int i=0; i+p.size()<=s.size(); i++){
        //     string substring = s.substr(i, p.size());
        //     sort(substring.begin(), substring.end());
        //     if(substring == sortedP) res.push_back(i);
        // }
        // return res;
        for(char c:p) count[c - 'a']++;
        int l=0, r=0, req=p.size();
        while(r<s.size()){
            if(count[s[r]-'a'] > 0) req--;
            count[s[r] - 'a']--;
            r++;

            if(req == 0) res.push_back(l);

            if(r-l == p.size()){
                if(count[s[l] - 'a'] >=0) req++;
                count[s[l] - 'a']++;
                l++;
            }
        }
        return res;
    }
};