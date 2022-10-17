class Solution {
public:
    bool checkIfPangram(string s) {
        vector<bool>vis(26,false);
        for(int i = 0 ; i < s.size() ; i++){
            vis[s[i]-'a'] = true;
        }
        for(int i = 0 ; i < 26 ; i++){
            if(vis[i] == false) return false;
        }
        return true;
    }
};