class Solution {
public:
    // int solveUsingRec(string& s, string& t, int i, int j){
    //     if(j == t.size()) return 1;
    //     if(i == s.size()) return 0;

    //     if(s[i] == t[j]) return solveUsingRec(s, t, i+1, j+1) + solveUsingRec(s, t, i+1, j);
    //     else return solveUsingRec(s, t, i+1, j);
    // }

    int solveUsingMem(string& s, string& t, int i, int j, vector<vector<int>>& dp){
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]){
            dp[i][j] = solveUsingMem(s, t, i+1, j+1, dp) + solveUsingMem(s, t, i+1, j, dp);
        }
        else{
            dp[i][j] = solveUsingMem(s, t, i+1, j, dp);
        }
        return dp[i][j];
    }
    
    int numDistinct(string s, string t) {
        int n=s.size(), m=t.size();
        if(n < m) return 0;

        // return solveUsingRec(s, t, 0, 0);
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solveUsingMem(s, t, 0, 0, dp);
    }
};