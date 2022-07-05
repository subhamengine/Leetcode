class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i , int j , vector<vector<int>>& triangle , int m){
        if(i == m) return triangle[i][j];
        if(dp[i][j]) return dp[i][j];
        int d = triangle[i][j] + solve(i+1,j,triangle,m);
        int r = triangle[i][j] + solve(i+1,j+1,triangle,m);
        return dp[i][j] = min(d,r);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        dp.resize(m+1,vector<int>(m+1));
        
        for(int j = 0 ; j < m ; j++){
            dp[m-1][j] = triangle[m-1][j];
        }
        for(int i = m-2 ; i >= 0 ; i--){
            for(int j = i ; j >= 0 ; j--){
                int d = triangle[i][j] + dp[i+1][j];
                int r = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(d,r);
            }
        }
        return dp[0][0];
    }
};