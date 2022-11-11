class Solution {
public:
    int countGoodSubstrings(string s) {
        int k = 3;
        int j = 0 ;
        int ans =0;
        unordered_map<char,int>mp;
        for(int i = 0 ; i < s.size() ; i++){
            mp[s[i]]++;
            if(i-j+1 == k){
                if(mp.size() == k){
                    ans++;
                }
                mp[s[j]]--;
                if(mp[s[j]] == 0) mp.erase(s[j]);
                j++;
            }
            
        }
        return ans;
    }
};