class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,0);
        
        for(int i = 0 ; i < n ; i++){
            if(color[i] == 0){
                queue<int>q;
                color[i] = 1;
                q.push(i);
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(auto it:graph[node]){
                        if(color[it] == color[node]) return false;
                        else if(color[it] == 0){
                            color[it] = -color[node];
                            q.push(it);
                        }
                    }
                }
            }
        }
        return true;
    }
};