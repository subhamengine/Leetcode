class Solution {
public:
//     int dp[1001][1001];
//     int solve(string s1, string s2 , int n , int m){
//         if(n == 0 or m == 0) return 0;
//         if(dp[n][m] != -1)return dp[n][m];
//         if(s1[n-1] == s2[m-1]){
//             return dp[n][m] = 1 + solve(s1,s2,n-1,m-1);
//         }
//         else{
//             return dp[n][m] = max(solve(s1,s2,n-1,m),solve(s1,s2,n,m-1));
//         }
        
//     }
    
    
    int longestCommonSubsequence(string s1, string s2) {
       
        
        //top-down
        int m = s1.size(), n = s2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1));
        
        for(int i = 0 ; i < m+1 ; i++){
            for(int j = 0 ; j < n+1 ; j++){
                if(i == 0 || j == 0)dp[i][j] = 0;
            }
        }
        
        for(int i = 1 ; i < m+1 ; i++){
            for(int j = 1 ; j < n+1 ; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};