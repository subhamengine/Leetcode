class Solution {
public:
    void solve(vector<vector<int>>&ans , vector<int>curr , int k , int n){
        if(curr.size() == k and n == 0){
            ans.push_back(curr);
            return;
        }
        if(curr.size() < k){
            for(int i = curr.size() == 0 ? 1 : curr.back()+1 ; i <= 9 ; i++){
                if(n - i >= 0){
                    curr.push_back(i);
                    solve(ans,curr,k,n-i);
                    curr.pop_back();
                }
                else break;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>curr;
        solve(ans,curr,k,n);
        return ans;
    }
};