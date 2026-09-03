class Solution {
public:
    int solve(string a, string b){
        int n = a.length(), m = b.length();
        vector<int> curr(m+1, 0);
        vector<int> next(m+1, 0);

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                int ans = 0;
                if(a[i] == b[j]){
                    ans = 1+next[j+1];
                }
                else{
                    ans = max(next[j] , curr[j+1]);
                } 
                curr[j]=ans;
            }
            next = curr;
        }
        return curr[0];
    }

    int longestPalindromeSubseq(string s) {
        string org = s;
        reverse(s.begin(), s.end());
        string rev = s;
        return solve(org, rev); 
    }
};