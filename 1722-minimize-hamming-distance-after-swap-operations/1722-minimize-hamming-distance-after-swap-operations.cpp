class Solution {
public:
    vector<vector<int>>adjList;
    vector<int>indices;
    vector<bool>vis;
    
    void dfs(vector<int>&source, int i){
        vis[i] = true;
        indices.push_back(i);
        for(auto &it: adjList[i]){
            if(!vis[it]){
                dfs(source,it);
            }
        }
    }
    
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int ans= 0;
        if(allowedSwaps.size() == 0){
            for(int i = 0 ; i < source.size() ; i++){
                if(source[i]!=target[i])ans++;
            }
            return ans;
        }
        
        adjList.resize(source.size());
        vis.resize(source.size(),false);
        for(auto &it:allowedSwaps){
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        
        for(int i = 0 ; i < source.size() ; i++){
            if(vis[i] == false){
                indices.clear();
                dfs(source,i);
                unordered_map<int,int> mp;
                for(auto e: indices)
                    mp[source[e]]++;
                for(auto e: indices){
                    if (mp[target[e]] < 1) ans++;
                    mp[target[e]]--;  
                }
                
            }
        }
        return ans;
    }
};