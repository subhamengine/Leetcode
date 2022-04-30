class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int>mp;
        for(auto it:edges){
            mp[it[0]]++;
            mp[it[1]]++;
        }
        for(auto it:mp){
            if(it.second == edges.size()) return it.first;
        }
        return -1;
    }
};