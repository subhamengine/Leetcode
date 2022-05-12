class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>nums,int n,int i){
        if(i == n-1){
            ans.push_back(nums);
            return;
        }
        for(int k = i ; k < n ; k++){
            swap(nums[i],nums[k]);
            solve(ans,nums,n,i+1);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        solve(ans,nums,n,0);
        return ans;
    }
};