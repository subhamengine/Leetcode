class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i, int j, vector<vector<int>>& grid){
        
        if(i == 0 and j == 0) return grid[i][j];
        int left = INT_MAX, right = INT_MAX;
        if(dp[i][j]) return dp[i][j];
        if(j-1>=0)
        left = grid[i][j] + solve(i,j-1,grid);
        if(i-1>=0)
        right = grid[i][j] + solve(i-1,j,grid);
        return dp[i][j] = min(left,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        dp.resize(m,vector<int>(n));
        return solve(m-1,n-1,grid);
    }
};