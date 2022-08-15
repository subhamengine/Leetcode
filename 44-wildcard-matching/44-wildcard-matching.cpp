class Solution {
public:
    bool help(string &s1, string &s2, int i, int j, vector<vector<int>>&dp){
        if(i < 0 and j < 0) return true;
        if(i < 0 and j >= 0) return false;
        if(i >= 0 and j < 0){
            for(int q = 0 ; q <= i ; q++){
                if(s1[q] != '*') return false;
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j] or s1[i] == '?') return dp[i][j] =  help(s1,s2,i-1,j-1,dp);
        if(s1[i] == '*') return dp[i][j] = ( (help(s1,s2,i-1,j,dp) or help(s1,s2,i,j-1,dp)));
        return dp[i][j] =  false;
        
    }
    bool isMatch(string s2, string s1) {
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size(),-1));
        return help(s1,s2,s1.size()-1,s2.size()-1,dp);
    }
};