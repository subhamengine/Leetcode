class Solution {
public:
    int maximumUnits(vector<vector<int>>& box, int truckSize) {
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>>pq;
        for(int i = 0 ; i < box.size() ; i++){
            int t = box[i][0] * box[i][1];
            pq.push({t/box[i][0],{box[i][0],box[i][1]}});
        }
        int ans = 0;
        while(!pq.empty() and truckSize){
            auto it = pq.top();
            if(it.second.first <= truckSize){
                ans+=(it.first)*(it.second.first);
                truckSize-=it.second.first;
            }
            else{
                ans+=it.first * truckSize;
                truckSize = 0;
            }
            pq.pop();
        }
        return ans;
    }
};