class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int ans = 0;
        int d[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        queue<pair<int,int>>q;
        vector<vector<bool>>vis(r,vector<bool>(c,false));
        
        if(grid[0][0] == 1 || grid[r-1][c-1] == 1) return -1;
        q.push({0,0});
        vis[0][0] = true;
        
        while(!q.empty()){
            int sz = q.size();
            ++ans;
            for(int i =0 ; i < sz ; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x == r-1 and y == c-1) return ans;
                
                for(int j = 0 ; j < 8 ; j++){
                    int x1 = x+d[j][0];
                    int y1 = y+d[j][1];
                    
                    if(x1 >= 0 and y1 >= 0 and x1 < r and y1 < c){
                        if(!vis[x1][y1] and grid[x1][y1] == 0){
                            q.push({x1,y1});
                            vis[x1][y1] = true;
                        }
                    }
                }
            }
        }
        return -1;
    }
};