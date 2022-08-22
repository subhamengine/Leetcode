class Solution {
public:
    int help(int index, int buy, int cap, vector<int>&prices, vector< vector < vector < int>>> &dp){
        if(index == prices.size()) return 0;
        if(cap == 0) return 0;
        if(dp[index][buy][cap] != -1) return dp[index][buy][cap];
        int p = 0;
        if(buy){
            p = max( -prices[index]+help(index+1,0,cap,prices,dp) , help(index+1,1,cap,prices,dp));
        }
        else{
            p = max( prices[index]+help(index+1,1,cap-1,prices,dp) , help(index+1,0,cap,prices,dp));
        }
        return dp[index][buy][cap] = p;
    }
    
    int maxProfit(vector<int>& prices) {
        vector< vector < vector < int>>> dp(prices.size()+1, vector< vector<int> >(3 , vector<int>(3,-1)));
        
        return help(0,1,2,prices,dp);
    }
};