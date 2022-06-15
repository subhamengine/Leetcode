class Solution {
public:
    static bool comp(string &a , string &b){
        return a.size() < b.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int n = words.size();
        if(n == 1) return 1;
        unordered_map<string,int>dp;
        int res = 0;
        for(auto str : words){
            for(int i = 0 ; i < str.size() ; i++){
                string pre = str.substr(0,i) + str.substr(i+1);
                dp[str] = max(dp[str],dp.find(pre) == dp.end() ? 1 : dp[pre]+1);
            }
            res = max(res,dp[str]);
        }
        return res;
    }
};