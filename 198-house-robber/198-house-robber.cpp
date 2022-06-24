class Solution {
public:
//     int solve(int index , vector<int>&nums ,vector<int>&dp){
//         if(index < 0) return 0;
//         if(dp[index] != -1) return dp[index];
//         if(index == 0) return dp[index] = nums[index];  
        
//         int pic = nums[index] + solve(index-2,nums,dp);
//         int nonPic = 0 + solve(index-1,nums,dp);
//         return dp[index] = max(pic,nonPic);
//     }
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n==1)return nums[0];
        int ptr1 = nums[0];
        int ptr2 = max(nums[0],nums[1]);
        
        for(int i = 2 ; i < n ; i++){
            int newNum = max(nums[i] + ptr1 , ptr2);
            ptr1 = ptr2;
            ptr2 = newNum;
        }
        return ptr2;
    }
};