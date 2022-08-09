class Solution {
public:
    bool solve(int i, vector<int>&nums, int n,vector<int>&dp){
        if(i == n){
            return true;
        }
        bool res = false;
        if(dp[i]!=-1) return dp[i];
        if(i+1 < n && nums[i] == nums[i+1]){
            res = solve(i+2,nums,n,dp);
            if(i+2 < n and nums[i] == nums[i+2]){
                res = res || solve(i+3,nums,n,dp);
            }
        }
        if(i+2 < n and nums[i+1] - nums[i] == 1 and nums[i+2] - nums[i+1] ==1) res = res || solve(i+3,nums,n,dp);
        return dp[i] = res;
        
    }
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        if( n == 2){
            return nums[0] == nums[1];
        }
        vector<int>dp(n+1,-1);
        return solve(0,nums,n,dp);
    }
};