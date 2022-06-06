class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& opr) {
        map<int,int>mp;
        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]] = i;
        }
        for(int i = 0 ; i < opr.size() ; i++){
            nums[mp[opr[i][0]]] = opr[i][1];
            mp.insert({opr[i][1],mp[opr[i][0]]});
            mp.erase(opr[i][0]);
        }
        return nums;
    }
};