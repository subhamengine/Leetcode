class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0;
        int sum = 0;
        int ans = INT_MAX;
        for(int i = 0 ; i < nums.size() ; i++){
            if(sum < target){
                sum+=nums[i];
            }
            if(sum >= target){
                while(sum >= target){
                    ans = min(ans,i-start+1);
                    sum-=nums[start];
                    start++;
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};