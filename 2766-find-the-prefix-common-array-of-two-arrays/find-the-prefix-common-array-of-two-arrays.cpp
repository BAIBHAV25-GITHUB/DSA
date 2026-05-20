class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> res(n);
        int cnt = 0;
        unordered_map<int, int> mp;

        for(int i =0; i < n; i++){
            mp[A[i]]++;
            if(mp[A[i]] == 2){
                cnt += 1;
            }
            mp[B[i]]++;
            if(mp[B[i]] == 2){
                cnt += 1;
            }

            res[i] = cnt;
        }
        return res;
    }
};