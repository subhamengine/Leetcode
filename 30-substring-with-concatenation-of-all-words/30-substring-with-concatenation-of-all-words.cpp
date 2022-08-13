class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>ans;
        int len = words[0].size();
        if(s.size() < words.size()*len) return ans;
        unordered_map<string,int>mp;
        
        for(auto it:words) mp[it]++;
        
        for(int i = 0 ; i <= s.size() - words.size()*len ; i++){
            
            unordered_map<string,int>cpy = mp;
            
            for(int j = 0 ; j < words.size() ; j++){
                
                string temp = s.substr(i+j*len,len);
                
                if(cpy.find(temp) != cpy.end()){
                    if(cpy[temp] == 1){
                        cpy.erase(temp);
                        
                    }else{
                        cpy[temp]--;
                    }
                    if(cpy.empty()){
                        ans.push_back(i);
                        break;
                    }
                }
                else break;
                
            }
        }
        return ans;
    }
};