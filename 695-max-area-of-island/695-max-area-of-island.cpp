class Solution {
public:
    int dfs(vector<vector<int>>& grid, int row, int col) {
        int m = grid.size(), n = grid[0].size(), area = 1;
        grid[row][col] = 2;
        vector<int> dir({-1,0,1,0,-1});
        for (int i = 0; i < 4; i++) {
            int r = row+dir[i], c = col+dir[i+1];
            if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1) 
                area += dfs(grid, r, c);
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>vis(n+1,vector<bool>(m+1,false));
       
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(vis[i][j] == false and grid[i][j]){
                    int area = 1;
                    
                    ans = max(ans,dfs(grid,i,j));
                    
                    
                }
            }
        }
        return ans;
    }
};