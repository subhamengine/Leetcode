class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
        if(l1 + l2 != l3) return false;
        vector<vector<bool>>dp(l2+1,vector<bool>(l1+1,false));
        dp[0][0] = true;
        
        for(int j = 1 ; j < dp[0].size() ; j++){
            dp[0][j] = dp[0][j-1] && (s1[j-1] == s3[j-1]);
        }
        for(int i = 1 ; i < dp.size() ; i++){
            dp[i][0] = dp[i-1][0] && (s2[i-1] == s3[i-1]);
        }
        for(int i = 1 ; i < dp.size() ; i++){
            for(int j = 1 ; j < dp[0].size() ; j++){
                
                dp[i][j] = (dp[i-1][j] && (s2[i-1] == s3[i+j-1])) or (dp[i][j-1] && (s1[j-1] == s3[i+j-1]));
            }
        }
        return dp[l2][l1];
    }
};