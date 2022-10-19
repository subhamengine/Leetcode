class comp{
    public:
        bool operator()(const pair<int,string>&p1 , const pair<int,string>&p2){
            return p1.first>p2.first || (p2.first == p1.first and p1.second < p2.second);
        }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for(auto it:words){
            mp[it]++;
        }
        
        
        vector<string>ans;
        priority_queue<pair<int,string>,vector<pair<int,string>>,comp>pq;
        
        for(auto it:mp){
            pq.push({it.second,it.first});
            if(pq.size() > k) pq.pop();
        }
        
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};