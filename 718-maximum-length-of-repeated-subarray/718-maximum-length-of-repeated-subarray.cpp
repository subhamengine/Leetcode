class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        
        for(int i = 0 ; i < n+1 ; i++){
            for(int j = 0 ; j < m+1 ; j++){
                if(i == 0 || j == 0)dp[i][j] = 0;
            }
        }
        int val = INT_MIN;
        for(int i = 1 ; i < n+1 ; i++){
            for(int j = 1 ; j < m+1 ; j++){
                if(nums1[i-1] == nums2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                
                }
                else{
                    dp[i][j] = 0;
                    
                }
                val = max(val,dp[i][j]);
            }
        }
        return val;
    }
};