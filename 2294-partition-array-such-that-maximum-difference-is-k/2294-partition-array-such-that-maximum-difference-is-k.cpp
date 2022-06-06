class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        if(nums.size()<=1)return nums.size();
        
        sort(nums.begin(),nums.end());
        
        int min = nums[0];
        int ans = 1;
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] - min > k){
                min = nums[i];
                ans++;
            }
        }
        return ans;
    }
};