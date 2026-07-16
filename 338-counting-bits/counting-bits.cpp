class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> b(n+1);
        b[0] = 0;
        for(int i=1; i<=n; i++){
            b[i] = b[i/2]+(i%2);
        }
        return b;
    }
};