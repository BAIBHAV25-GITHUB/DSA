class Solution {
public:
    // int solveUsingRec(vector<int>& arr, map<pair<int, int>, int>& mp, int left, int right){
    //     if(left == right) return 0;

    //     int ans = INT_MAX;
    //     for(int i=left; i<=right; i++){
    //         ans = min(ans, mp[{left, i}] * mp[{i+1, right}] 
    //         + solveUsingRec(arr, mp, left, i)
    //         + solveUsingRec(arr, mp, i+1, right));
    //     }
    //     return ans;
    // }

    int solveUsingMem(vector<int>& arr, vector<vector<int>>& maxi, int left, int right, vector<vector<int>>& dp){
        if(left == right) return 0;

        if(dp[left][right] != -1) return dp[left][right];

        int ans = INT_MAX;
        for(int i=left; i<right; i++){
            ans = min(ans, maxi[left][i] * maxi[i+1][right] 
            + solveUsingMem(arr, maxi, left, i, dp)
            + solveUsingMem(arr, maxi, i+1, right, dp));
        }
        dp[left][right] = ans;
        return dp[left][right];
    }
    
    int mctFromLeafValues(vector<int>& arr) {
        int n =arr.size(); 
        vector<vector<int>> maxi(n, vector<int>(n));
        
        for(int i=0; i<n; i++){
            maxi[i][i] = arr[i];
            for(int j=i+1; j<n; j++){
                maxi[i][j] = max(arr[j], maxi[i][j-1]);
            }
        }

        // return solveUsingRec(arr, mp, 0, n-1);

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solveUsingMem(arr, maxi, 0, n-1, dp);
    }
};