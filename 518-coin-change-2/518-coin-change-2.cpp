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
        // return help(coins.size()-1,coins,amount,dp);
        
        for(int j = 0 ; j <= amount ; j++){
            dp[0][j] = (j%coins[0] == 0) ;
        }
        
        
        for(int i = 1 ; i < coins.size() ; i++){
            for(int j = 0 ; j <= amount ; j++){
                int take =  0, notTake = 0;
                
                if(coins[i] <= j){
                    take =  dp[i][j-coins[i]];
                }
                notTake = dp[i-1][j];
                dp[i][j] = take+notTake;
            }
        }
        return dp[coins.size()-1][amount];
    }
};