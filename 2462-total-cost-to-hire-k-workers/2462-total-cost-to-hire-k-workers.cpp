class Solution {
public:
    long long totalCost(vector<int>& cost, int k, int c) {
        int n = cost.size();
        priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>>pq;
        int i = 0, j = n-1;
        if(i == j) return cost[0];
        
        while(i < j && c > 0){
            c--;
            pq.push({cost[i],i});
            pq.push({cost[j],j});
            i++,j--;
        }
        long long ans = 0;
        
        while( k > 0 and i <= j){
            k--;
            pair<int,int>p = pq.top();
            pq.pop();
            ans+=p.first;
            if(p.second < i){
                pq.push({cost[i],i});
                i++;
            } 
            else{
                pq.push({cost[j],j});
                j--;
            }
        }
        while(k > 0 && !pq.empty()){
            ans+=pq.top().first;
            pq.pop();
            k--;
        }
        return ans;
    }
};