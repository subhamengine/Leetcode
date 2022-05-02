class Solution {
public:
    vector<vector<int>>adjList;
    vector<bool>vis;
    vector<int>indices;
    string indiceString;
    
    
    void dfs(string &s, int i){
        vis[i] = true;
        indices.push_back(i);
        indiceString+=s[i];
        for(auto &it:adjList[i]){
            if(!vis[it]){
                dfs(s,it);
            }
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        adjList.resize(s.size());
        vis.resize(s.size(),false);
        
        for(auto &it:pairs){
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        
        for(int i = 0 ; i < s.size() ; i++){
            if(!vis[i]){
                indices.clear();
                indiceString = "";
                dfs(s,i);
                sort(indices.begin(),indices.end());
                sort(indiceString.begin(),indiceString.end());
                for(int i = 0 ; i < indiceString.size() ; i++){
                    s[indices[i]] = indiceString[i];
                }
            }
        }
        return s;
    }
};