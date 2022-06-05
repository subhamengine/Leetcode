class Solution {
public:
    int ans = 0;
    bool valid(vector<vector<int>>&board, int row , int col){
        for(int i = row ; i >= 0 ; i--){
            if(board[i][col] == 1) return false;
        }
        for(int i = row, j = col ; i >= 0 && j >= 0 ; i-- , j--){
            if(board[i][j] == 1) return false;
        }
        for(int i = row , j = col ; i >= 0 && j < board.size() ; i--, j++){
            if(board[i][j] == 1) return false;
        }
        return true;
    }
    void solve(vector<vector<int>>&board, int row){
        int n = board.size();
        if(row == n){
            ans++;
            return;
        }
        for(int i = 0 ; i < n ; i++){
            if(valid(board,row,i)){
                board[row][i] = 1;
                solve(board,row+1);
                board[row][i] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<int>>board(n,vector<int>(n,0));
        solve(board,0);
        return ans;
    }
};