class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int xCurrent = startFuel;
        int ans =0;
        priority_queue< int,vector<int> > pq;
        
        for(auto it:stations){
            int nextSta = it[0];
            int fuel = it[1];
            
            while(xCurrent < nextSta){
                if(!pq.size()) return -1;
                
                int maxFuel = pq.top();
                pq.pop();
                xCurrent += maxFuel;
                ans++;
            }
            pq.push(fuel);
        }
        
        while(xCurrent < target){
                if(!pq.size()) return -1;
                
                int maxFuel = pq.top();
                pq.pop();
                xCurrent += maxFuel;
                ans++;
            }
        return ans;
    }
};