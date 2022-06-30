class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int mid = n/2;
        int ele = nums[mid];
        int ans = 0;
        for(auto it:nums){
            ans+=abs(ele-it);
        }
        return ans;
    }
};