class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if(mat.empty()) return {};

        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int, vector<int>> diag;
        for(int i = 0; i < m; i++){
            for(int j= 0; j < n; j++){
                diag[i+j].push_back(mat[i][j]);
            }
        }

        vector<int> ans;
        for(int d = 0; d < m+n-1; d++){
            if(d % 2 == 0){
                for(int i = diag[d].size()-1; i >=0; i--){
                    ans.push_back(diag[d][i]);
                }
            }
            else{
                for(int x : diag[d]){
                    ans.push_back(x);
                }
            }
        }

        return ans;
    }
};