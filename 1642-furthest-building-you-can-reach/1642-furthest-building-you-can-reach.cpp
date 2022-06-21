class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>>pq;
        int i =0 ;
        for( i = 0 ; i < heights.size()-1 ; i++){
            if(heights[i+1]-heights[i] > 0){
                pq.push(heights[i+1]-heights[i]);
            }
            if(pq.size()>ladders){
                int t = pq.top();
                pq.pop();
                if(t <= bricks){
                    bricks-=t;
                }
                else return i;
            }
        }
        return i;
    }
};