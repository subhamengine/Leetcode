class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>ans(m,0);
        for(int j = 0 ; j < m ; j++){
            bool reachEnd = true;
            int indexI = 0, indexJ = j;
            while(indexI >= 0 && indexI < n && indexJ >= 0 and indexJ < m and reachEnd){
                
                if(grid[indexI][indexJ] == 1 && indexJ < m-1 && grid[indexI][indexJ+1] != -1){
                    indexI = indexI+1;
                    indexJ = indexJ+1;
                }else if(grid[indexI][indexJ] == -1 && indexJ > 0 && grid[indexI][indexJ-1] != 1){
                    indexI = indexI+1;
                    indexJ = indexJ-1;
                }else{
                    reachEnd = false;
                    break;
                }
            }
            if(reachEnd)ans[j]=indexJ;
            else ans[j]=-1;
        }
        return ans;
    }
};