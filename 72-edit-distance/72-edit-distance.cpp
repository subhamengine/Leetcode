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
    
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return help(n-1,m-1,word1,word2,dp);
    }
};