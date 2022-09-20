class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.size(),ans =1;
        vector<int>dp(n+1,1);
        
        for(int i = 1 ; i < n ; i++){
            if(s[i] - s[i-1] == 1){
                dp[i] = max(1+dp[i-1],dp[i-1]);
            }
            ans = max(ans,dp[i]);
            
        }
        
        return ans;
    }
};