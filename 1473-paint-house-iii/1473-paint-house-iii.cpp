class Solution {
public:
    int dp[101][21][101];
    int help(int i, int l, int t, vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target){
        if(t > target) return INT_MAX/2;
        if(i == m){
            
            if(t == target){
                return 0;
            }
            else return INT_MAX/2;
        }
        if(dp[i][l][t] != -1) return dp[i][l][t];
        else{
            int ans = INT_MAX/2;
            if(houses[i] == 0){
                for(int j = 0 ; j < n ; j++){
                    ans = min(ans, cost[i][j] + help(i+1, j+1,(l == j+1)?t:t+1 ,houses, cost,m,n,target));
                }
            }
            else{
                ans = min(ans,help(i+1, houses[i] ,(houses[i] == l)?t:t+1 ,houses, cost,m,n,target));
            }
            return dp[i][l][t] = ans;
        }
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        int ans = help(0,0,0,houses,cost,m,n,target);
        return ans == INT_MAX/2 ? -1:ans;
    }
};