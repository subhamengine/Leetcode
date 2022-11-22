class Solution {
public:
    int helper(int i,vector<int>&dp){
        if(i==0) return 0;
        if(dp[i]!=-1) return dp[i];
        int minCnt=INT_MAX;
        for(int num=1;num<=sqrt(i);++num){
            int curCnt=1+helper(i-(num*num),dp);
            minCnt=min(curCnt,minCnt);
        }
        return dp[i]=minCnt;
    }
    
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return helper(n,dp);
    }
};