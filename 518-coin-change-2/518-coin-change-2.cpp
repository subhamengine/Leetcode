class Solution {
public:
    int help(int i, vector<int>&coins, int amt,vector<vector<int>>&dp ){
        if(i == 0 ){
            return (amt%coins[i] == 0) ;
            
        }
        if(dp[i][amt]!=-1) return dp[i][amt];
        int take =  0, notTake = 0;
        if(coins[i] <= amt){
            take =  help(i,coins,amt-coins[i],dp);
        }
        notTake = help(i-1,coins,amt,dp);
        return dp[i][amt] = take+notTake;
        // return take+notTake;
    }
    
    
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return help(coins.size()-1,coins,amount,dp);
    }
};