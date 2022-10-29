class Solution {
public:
    
   
    int earliestFullBloom(vector<int>& p, vector<int>& g) {
        vector<pair<int,int>>vec;
        for(int i = 0 ; i < p.size() ; i++){
            
            
            vec.push_back({g[i],p[i]});
        }
        sort(vec.rbegin(),vec.rend());
        int ans = 0;
        int prevEnd = 0;
        for(auto it:vec){
            int plantTime = it.second;
            int growTime = it.first;
            int totalTime = plantTime+growTime;
            ans = max(ans,totalTime+prevEnd);
            prevEnd+=plantTime;
        }
        return ans;
    }
};