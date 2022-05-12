class Solution {
public:
    void solve(vector<int>nums,vector<vector<int>>&ans,int i,int n){
        if(i == n-1){
            ans.push_back(nums);
            return;
        }
        for(int k = i ; k < n ; k++){
            if(i!=k and nums[i] == nums[k])continue;
            swap(nums[i],nums[k]);
            solve(nums,ans,i+1,n);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n = nums.size();
        solve(nums,ans,0,n);
        return ans;
    }
};