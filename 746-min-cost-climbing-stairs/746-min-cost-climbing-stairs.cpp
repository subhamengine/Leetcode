class Solution {
public:
    
    int solve(int index , vector<int>& cost , vector<int>&dp){
        if(index == 0 || index == 1){
            return dp[index] = cost[index];
        }
        if(dp[index] != -1) return dp[index];
        return dp[index] = min(cost[index] + solve(index-1,cost,dp) , cost[index] + solve(index-2,cost,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // vector<int>dp(n+1,0);
        // for(int i = 2 ; i < n+1 ; i++){
        //     int oneStep = dp[i-1] + cost[i-1];
        //     int twoStep = dp[i-2] + cost[i-2];
        //     dp[i] = min(oneStep,twoStep);
        // }
        // return dp[n];
        vector<int>dp(n+1,-1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        cost.push_back(0);
        return solve(n,cost,dp);
    }
};