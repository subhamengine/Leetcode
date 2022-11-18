class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k == 1) return 0;
        sort(nums.begin(),nums.end());
        int ans = INT_MAX;
        int j = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(i-j+1==k){
                ans = min(ans,nums[i]-nums[j]);
                j++;
            }
        }
        return ans;
    }
};