class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>>nextState(n,vector<int>(m,0));
        int x[] = {-1,0,+1,0,-1,-1,1,1};
        int y[] = {0, 1,0,-1,-1,+1,1,-1};
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                int person = board[i][j];
                if(person){
                    int lc = 0;
                    for(int k = 0 ; k < 8 ; k++){
                        int newX = i+x[k], newY = j+y[k];
                        if(newX>=0 and newX < n and newY >= 0 and newY < m){
                            if(board[newX][newY])lc++;
                            
                        }
                    }
                    if(lc<2){
                        nextState[i][j] = 0;
                    }
                    else if(lc == 2 or lc == 3){
                        nextState[i][j] = 1;
                    }
                    else if(lc>3){
                        nextState[i][j] = 0;
                    }
                }else{
                    int lc = 0;
                    for(int k = 0 ; k < 8 ; k++){
                        int newX = i+x[k], newY = j+y[k];
                        if(newX>=0 and newX < n and newY >= 0 and newY < m){
                            if(board[newX][newY])lc++;
                            
                        }
                    }
                    if(lc==3){
                        nextState[i][j] = 1;
                    }
                    else nextState[i][j] = 0;
                }
            }
        }
        board = nextState;
        return;
    }
};