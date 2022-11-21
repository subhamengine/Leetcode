class Solution {
public:
    int xc[4]={1,-1,0,0};
    int yc[4]={0,0,1,-1};
    
  
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        int n = maze.size();
        int m = maze[0].size();
        int ans = 0;
        queue<pair<int,int>>q;
        q.push({e[0],e[1]});
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        vis[e[0]][e[1]] = true;
        
        while(!q.empty()){
            int sz = q.size();
            ans++;
            while(sz--){
                pair<int,int>t = q.front();
                q.pop();
                
                for(int i = 0 ; i < 4 ; i++){
                    int newx = t.first + xc[i];
                    int newy = t.second + yc[i];
                    if(newx >= 0 and newx < n and newy >= 0 and newy < m){
                        if(maze[newx][newy] != '.') continue;
                        if(vis[newx][newy]) continue;
                        
                        if(newx == 0 || newx == n-1 || newy == 0 || newy == m-1) return ans;
                        vis[newx][newy] = true;
                        q.push({newx,newy});
                    }
                }
            }
        }
        
        return -1;
        
    }
};