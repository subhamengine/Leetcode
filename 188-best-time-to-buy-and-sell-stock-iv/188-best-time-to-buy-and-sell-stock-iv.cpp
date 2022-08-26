class Solution {
public:
    
    int help(int index, bool buy, int cap,  vector<int>& prices, vector<vector<vector<int>>>&dp){
        if(index == prices.size()) return 0;
        if(cap == 0) return 0;
        if(dp[index][buy][cap] != -1) return dp[index][buy][cap];
        
        int price = 0;
        if(buy){
            price = max( -prices[index]+help(index+1,0,cap,prices,dp) , help(index+1,1,cap,prices,dp));
        }
        else{
            price = max( prices[index]+help(index+1,1,cap-1,prices,dp) , help(index+1,0,cap,prices,dp));
        }
        return dp[index][buy][cap] = price;                                        
    }
    
    
    
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(3,vector<int>(k+1,-1)));
        return help(0,true,k,prices,dp);;
                                      
    }
};