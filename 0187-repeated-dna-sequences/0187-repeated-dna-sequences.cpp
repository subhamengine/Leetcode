class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int k = 10,j=0;
        unordered_map<string,int>mp;
        cout<<s.size();
        for(int i = 0 ; i < s.size() ; i++){
            if(i-j+1==k){
                string str = s.substr(j,k);
                
                mp[str]++;
                j++;
            }
        }
        vector<string>ans;
        for(auto it:mp){
            if(it.second > 1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};