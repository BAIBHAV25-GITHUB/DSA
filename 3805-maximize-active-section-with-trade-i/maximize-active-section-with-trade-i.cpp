class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int activeCnt = count(s.begin(), s.end(), '1');
        vector<int> inActive;
        int i=0;
        while(i < n){
            if(s[i] == '0'){
                int start = i;
                while(i<n && s[i] == '0') i++;
                inActive.push_back(i-start);
            }
            else i++;
        }

        int maxi = 0;
        for(int i=1; i<inActive.size(); i++){
            maxi = max(maxi, inActive[i]+inActive[i-1]);
        }
        return maxi+activeCnt;
    }
};