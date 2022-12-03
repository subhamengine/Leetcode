class comp{
    public:
        bool operator()(const pair<int,char> &p1, const pair<int,char> &p2){
            if(p1.first == p2.first){
                return p1.second > p2.second;
            }
            return p1.first < p2.first;
        }
};

class Solution {
public:
    
    
    
    
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        
        for(auto it:s){
            mp[it]++;
        }
        priority_queue<pair<int,char>,vector<pair<int,char>>,comp>pq;
        
        for(auto it:mp){
           pq.push({it.second,it.first});
        }
        s.erase();
        while(!pq.empty()){
            
            string temp(pq.top().first,pq.top().second);
            s+=temp;
            pq.pop();
        }
        return s;
        
    }
};