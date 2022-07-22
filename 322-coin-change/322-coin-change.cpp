class Solution {
public:
    int help(int i, vector<int>&coins, int amt, vector<vector<int>>&dp ){
        if(i == 0 ){
            if(amt%coins[i] == 0) return amt/coins[i];
            else return 1e9;
        }
        if(dp[i][amt]!=-1) return dp[i][amt];
        int take =  INT_MAX, notTake = 0;
        if(coins[i] <= amt){
            take = 1 + help(i,coins,amt-coins[i],dp);
        }
        notTake = 0 + help(i-1,coins,amt,dp);
        return dp[i][amt] = min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,0));
        int n = coins.size();
        
        for(int j = 0 ; j <= amount ; j++){
            if(j%coins[0] == 0)dp[0][j] = j/coins[0];
            else dp[0][j] = 1e9;
        }
        
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j <= amount ; j++){
                int take =  INT_MAX, notTake = 0;
                if(coins[i] <= j){
                    take = 1 + dp[i][j-coins[i]];
                }
                notTake = dp[i-1][j];
                dp[i][j] = min(take,notTake);
            }
        }
        
        return dp[n-1][amount] >= 1e9 ? -1:dp[n-1][amount] ;
    }
};