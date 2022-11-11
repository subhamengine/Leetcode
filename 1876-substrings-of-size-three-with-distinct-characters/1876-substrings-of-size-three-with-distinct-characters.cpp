class Solution {
public:
    int countGoodSubstrings(string s) {
        int ans = 0;
        for(int i = 1 ; i < s.size()-1 ; i++){
            if(s[i] != s[i-1] && s[i] != s[i+1] && s[i-1] != s[i+1]){
                ans++;
            }
        }
        return ans;
    }
};