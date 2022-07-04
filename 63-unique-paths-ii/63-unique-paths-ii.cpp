class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int m = a.size();
        int n = a[0].size();
        vector<vector<long>>dp(m,vector<long>(n,(long)0));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(a[i][j] == 1) dp[i][j] = 0;
                else if(i == 0 and j == 0) dp[i][j] = 1;
                else{
                    int up = 0, left = 0;
                    if(i > 0){
                        up = dp[i-1][j];
                    }
                    if(j > 0){
                        left = dp[i][j-1];
                    }
                    dp[i][j] = up+left;
                }
            }
        }return dp[m-1][n-1];
    }
};