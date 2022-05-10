class Solution {
public:
    void solve(vector<int>& candidates, vector<vector<int>>&ans, vector<int>curr, int index , int target){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        for(int i = index ; i < candidates.size() ; i++){
            if(candidates[i] > target) return;
            if(i > index and candidates[i-1] == candidates[i])continue;
            curr.push_back(candidates[i]);
            solve(candidates, ans, curr, i+1, target-candidates[i]);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int index = 0;
        vector<int>curr;
        vector<vector<int>>ans;
        solve(candidates,ans,curr,index,target);
        return ans;
    }
};