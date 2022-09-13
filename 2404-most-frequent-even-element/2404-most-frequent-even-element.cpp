class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int,greater<int>>mp;
        for(auto it:nums){
            if(it%2==0) mp[it]++;
        }
        if(mp.size() == 0) return -1;
        
        map<int,int,greater<int>>mp1;
        
        for(auto it:mp){
            // cout<<it.first<<" -> "<<it.second<<endl;
            mp1[it.second] = it.first;
        }
        for(auto it:mp1){
            cout<<it.first<<" -> "<<it.second<<endl;
            
        }
        return mp1.begin()->second;
        
       
        
       
        
    }
};