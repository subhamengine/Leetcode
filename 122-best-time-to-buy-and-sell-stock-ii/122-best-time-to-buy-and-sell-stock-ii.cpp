class Solution {
public:
    int help(int index, vector<int>&price , int buy, int n,vector<vector<int>>&dp){
        if(index == n) return 0;
        int p = 0;
        
        if(dp[index][buy] != -1) return dp[index][buy];
        
        if(buy){
            p = max( -price[index] + help(index+1,price,0,n,dp) , help(index+1,price,1,n,dp)  );
        }
        else{
            p = max(price[index] + help(index+1,price,1,n,dp) , help(index+1,price,0,n,dp));
        }
        return dp[index][buy] = p;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(3,-1));
        return help(0,prices,1,n,dp);
    }
};