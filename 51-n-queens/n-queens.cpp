class Solution {
public:
    vector<vector<string>> ans;

    bool isSafe(vector<string>& board, int r, int c, int n){
        int i = r, j = c;

        while(j >= 0){
            if(board[i][j] == 'Q') return false;
            j--;
        }

        i = r, j = c;
        while(i >= 0 && j >= 0){
            if(board[i][j] == 'Q') return false;
            i--, j--;
        }

        i = r, j = c;
        while(i < n && j >= 0){
            if(board[i][j] == 'Q') return false;
            i++, j--;
        }

        return true;
    }

    void solve(vector<string>& board, int c, int n){
        if(c >= n){
            ans.push_back(board);
            return;
        }

        for(int r = 0; r < n; r++){
            if(isSafe(board, r, c, n)){
                board[r][c] = 'Q';
                solve(board, c+1, n);
                board[r][c] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        solve(board, 0, n);
        return ans;
    }
};