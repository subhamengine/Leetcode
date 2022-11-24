class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    bool dfs(int i, int j, int count, vector<vector<char>>& board, string word, int n, int m){
        
        if(count == word.size() ) return true;
        if(i < 0 || j < 0 || i >= n || j >= m) return false;
        if(word[count] != board[i][j]) return false;
        
        char temp = board[i][j];                    
        board[i][j] = ' ';
        
        bool ans = dfs(i-1,j,count+1,board,word,n,m) || 
                   dfs(i+1,j,count+1,board,word,n,m) ||
                   dfs(i,j-1,count+1,board,word,n,m) ||
                   dfs(i,j+1,count+1,board,word,n,m);
        
        board[i][j] = temp;                         // make board as it is for the upcoming calls
        return ans;
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                vector<vector<bool>>vis(n,vector<bool>(m,false));
                if(board[i][j] == word[0] && dfs(i,j,0,board,word,n,m) == true) return true;
            }
        }
        return false;
        
    }
};