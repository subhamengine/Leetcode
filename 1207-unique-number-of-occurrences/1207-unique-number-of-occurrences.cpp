class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        
        for(auto it:arr){
            mp[it]++;
        }
        
        set<int>st;
        for(auto it:mp){
            if(st.find(it.second) != st.end()) return false;
            else st.insert(it.second);
        }
        return true;
    }
};