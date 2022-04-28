class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>>effort(m,vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        
        vector<vector<int>>dir = {{0,1},{0,-1},{1,0},{-1,0}};
        while(pq.size()){
            auto it = pq.top();
            pq.pop();
            int dist = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            if(dist > effort[row][col] ) continue;
            if(row == m-1 and col == n-1) return dist;
            
            for(auto it:dir){
                int newRow = row+it[0];
                int newCol = col+it[1];
                if(newRow>=0 and newRow<m and newCol >= 0 and newCol < n){
                    int newDist = max(dist,abs(heights[newRow][newCol] - heights[row][col]));
                    if(newDist < effort[newRow][newCol]){
                        effort[newRow][newCol] = newDist;
                        pq.push({newDist,{newRow,newCol}});
                    }
                }
            }
        }
            return 0;
    }
};