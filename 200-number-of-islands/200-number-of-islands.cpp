class Solution {
public:
    int x[4] = {1,-1,0,0};
    int y[4] = {0,0,1,-1};
    void help(int i, int j, vector<vector<bool>>&vis, vector<vector<char>>& grid){
        
        if(vis[i][j] != true){
            vis[i][j] = true;
            
            for(int cord = 0 ; cord < 4 ; cord++){
                int newX = i + x[cord];
                int newY = j + y[cord];
                if(newX >= 0 and newY >= 0 and newX < grid.size() and newY < grid[0].size() and grid[newX][newY] == '1' and vis[newX][newY] == false){
                    help(newX,newY,vis,grid);
                }
            }
        }
        return ;
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0, n = grid.size(), m = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == '1' and vis[i][j] == false){
                    help(i,j,vis,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};