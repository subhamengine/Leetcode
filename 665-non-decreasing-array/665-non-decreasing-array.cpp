class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        int count = 0;
        for(int i = 1 ; i < n and count < 2; i++){
            if(nums[i-1] > nums[i]){
                count++;
                if(i-2 < 0 or nums[i-2] <= nums[i]) nums[i-1] = nums[i];
                else nums[i] = nums[i-1];
            }
        }
        return count < 2;
        
    }
};