class Solution {
public:
    int distance(vector<vector<int>>&points , int i, int j){
        return abs(abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]));
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>>pq;
        int cost = 0;
        pq.push({cost,{0,0}});
        set<int>st;
        int num = points.size();
        
        while(!pq.empty() and st.size()<num){
            auto it = pq.top();
            pq.pop();
            int cur = it.second.first;
            int currCost = it.first;
            int endId = it.second.second;
            if(st.find(endId)!=st.end())continue;
            
            cost+=currCost;
            st.insert(endId);
            for(int i = 0 ; i < num ; i++){
                if(st.find(i) == st.end()){
                    pq.push({distance(points, endId, i),{endId,i}});
                }
            }
        }
        return cost;
    }
};