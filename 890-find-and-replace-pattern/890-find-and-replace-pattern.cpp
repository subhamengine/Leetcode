class Solution {
public:
    string f(string w){
        unordered_map<char,int>mp;
        for(auto it:w){
            if(!mp.count(it)){
                mp[it] = mp.size();
            }
        }
        for(int i = 0 ; i < w.size() ; i++){
            w[i] = 'a' + mp[w[i]];
        }
        return w;
    }
    
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>res;
        for(auto it : words){
            if(f(it) == f(pattern)){
                res.push_back(it);
            }
        }
        return res;
    }
};