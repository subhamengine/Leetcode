class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>mp;
        for(auto it:tasks){
            mp[it]++;
        }
        int ans = 0;
        for(auto &it:mp){
            if(it.second == 1) return -1;
            else ans += (it.second+2)/3;
        }
        return ans;
    }
};