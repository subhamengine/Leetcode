

class Solution {
public:
    struct comp{
        bool operator()(const pair<int,int>&a, const pair<int,int>&b) const{
            return a.second < b.second;
        }
    };
    int minSetSize(vector<int>& arr) {
       map<int,int>mp;
        int n = arr.size();
        priority_queue<pair<int,int>,vector<pair<int,int>> , comp>pq;
           for(int i = 0 ; i < n ; i++){
               mp[arr[i]]++;
           }
        for(auto it:mp){
            pq.push({it.first,it.second});
        }
        int curr = 0, count = 0;
        while(!pq.empty()){
            curr+= pq.top().second;
            pq.pop();
            count++;
            if(curr >= n/2) break;
        }
        return count;
    }
};