class Solution {
public:
    
    int minDeletions(string s) {
        unordered_map<char,int>mp;
        vector<int>freq;
        for(auto it:s){
            mp[it]++;
        }
        int ans =0;
        set<int>st;
        
        for(auto &it:mp){
            while(st.find(it.second) !=  st.end()){
                ans++;
                --it.second;
            }
            if(it.second > 0)st.insert(it.second);
        }
        return ans;
    }
};