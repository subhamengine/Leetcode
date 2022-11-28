class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,pair<int,int>>mp;
        for(auto it:matches){
            mp[it[0]].first +=1;
            mp[it[1]].second += 1;
            
        }
        
        vector<vector<int>>ans;
        vector<int>one;
        vector<int>two;
        for(auto it:mp){
            if(it.second.second == 0){
                one.push_back(it.first);
            }
            if(it.second.second == 1){
                two.push_back(it.first);
            }
        }
        ans.push_back(one);
        ans.push_back(two);
        return ans;
    }
};