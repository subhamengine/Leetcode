class Solution {
public:
    
    
    int minMutation(string start, string end, vector<string>& bank) {
        vector<int>diff;
        vector<char>col = {'A','C','G','T'};
        for(int i = 0 ; i < start.size() ; i++){
            if(start[i] != end[i])diff.push_back(i);
        }
        set<string>st;
        for(auto it:bank){
            st.insert(it);
        }
        queue<string>q;
        unordered_set<string>vis;
        
        q.push(start);
        vis.insert(start);
        int ans = 0;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                string curr = q.front();
                q.pop();
                if(curr == end) return ans;
                
                for(int i = 0 ; i < 8 ; i++){
                    char org = curr[i];
                    
                    for(int j = 0 ; j < 4 ; j++){
                        curr[i] = col[j];
                        if(st.find(curr)!=st.end()){
                            if(vis.find(curr) == vis.end()){
                                vis.insert(curr);
                                q.push(curr);
                            }
                        }
                    }
                    curr[i] = org;
                }
                
            }
            ans++;
        }
        
        
        return -1;
    }
};