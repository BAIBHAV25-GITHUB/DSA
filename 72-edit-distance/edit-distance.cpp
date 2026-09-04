class Solution {
public:
    // int solveUsingRec(string& a, string& b, int i, int j){
    //     if(i == a.length()) return b.length()-j;
    //     if(j == b.length()) return a.length()-i;

    //     int ans = 0;
    //     if(a[i] == b[j]) ans = solveUsingRec(a, b, i+1, j+1);
    //     else{
    //         int insert = 1+solveUsingRec(a, b, i, j+1);
    //         int deleted = 1+solveUsingRec(a, b, i+1, j);
    //         int replace = 1+solveUsingRec(a, b, i+1, j+1);

    //         ans = min(insert, min(deleted, replace));
    //     }
    //     return ans;
    // }

    int solveUsingMem(string& a, string& b, int i, int j, vector<vector<int>>& dp){
        if(i == a.length()) return b.length()-j;
        if(j == b.length()) return a.length()-i;

        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        if(a[i] == b[j]) ans = solveUsingMem(a, b, i+1, j+1, dp);
        else{
            int insert = 1+solveUsingMem(a, b, i, j+1, dp);
            int deleted = 1+solveUsingMem(a, b, i+1, j, dp);
            int replace = 1+solveUsingMem(a, b, i+1, j+1, dp);

            ans = min(insert, min(deleted, replace));
        }
        dp[i][j] = ans;
        return ans;
    }

    int minDistance(string word1, string word2) {
        int n=word1.length(), m=word2.length(); 
        if(n == 0) return m;
        if(m == 0) return n;

        // return solveUsingRec(word1, word2, 0, 0);

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solveUsingMem(word1, word2, 0, 0, dp);
    }
};