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
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        
        int ans = help(coins.size()-1,coins,amount,dp);
        return (ans == 1e9?-1:ans) ;
    }
};