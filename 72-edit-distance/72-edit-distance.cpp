class Solution {
public:
    int help(int i1, int i2, string s1, string s2,vector<vector<int>>&dp){
        if(i2 < 0) return i1+1;
        if(i1 < 0) return i2+1;
        
        if(dp[i1][i2] != -1) return dp[i1][i2];
        
        if(s1[i1] == s2[i2]){
            return 0 + help(i1-1,i2-1,s1,s2,dp);
        }
        int first = 0, second = 0, third = 0;
        
            first = 1 + help(i1,i2-1,s1,s2,dp);
            second = 1 + help(i1-1,i2,s1,s2,dp);
            third = 1 + help(i1-1,i2-1,s1,s2,dp);
        
        return dp[i1][i2] = min(first,min(second,third));
    }
    
    int minDistance(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int i = 0 ; i <= n ; i++){
            dp[i][0] = i;
        }
        for(int i = 0 ; i <= m ; i++){
            dp[0][i] = i;
        }
        
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    int first = 0, second = 0, third = 0;
                    
                    first = 1 + dp[i][j-1];
                    second = 1 + dp[i-1][j];
                    third = 1 + dp[i-1][j-1];
                    
                    
                    dp[i][j] = min( first   ,  min(second,third) );
                }
            }
        }
        return dp[n][m];
    }
};