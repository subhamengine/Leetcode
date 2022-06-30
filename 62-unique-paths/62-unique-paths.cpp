class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<long>>dp(m+1,vector<long>(n+1,(long)0));
        for(int i = 0 ; i <= m ; i++){
            for(int j = 0 ; j <= n ; j++){
                if(i == 0 or j == 0){
                    dp[i][j] = 1;
                }
            }
        }
        for(int i = 1 ; i <= m ; i++){
            for(int j = 1 ; j <= n ; j++){
                dp[i][j] = (long)dp[i][j-1] + (long)dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
};