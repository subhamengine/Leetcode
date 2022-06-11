class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum < x) return -1;
        int l = 0, r = 0 , ans = INT_MIN, curSum = 0;
        for(r = 0 ; r < nums.size() ; r++){
            curSum+=nums[r];
            while(curSum > sum-x and l <= r){
                curSum-=nums[l++];
            }
            if(curSum == sum-x) ans = max(ans,r-l+1);
        }
        return ans == INT_MIN ? -1: nums.size() - ans;
    }
};