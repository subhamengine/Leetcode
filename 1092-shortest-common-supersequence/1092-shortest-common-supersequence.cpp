class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        for(int i = 0 ; i < n+1 ; i++){
            for(int j = 0 ; j < m+1 ; j++){
                if(i == 0 or j == 0)dp[i][j] = 0;
            }
        }
        for(int i = 1 ; i < n+1 ; i++){
            for(int j = 1 ; j < m+1 ; j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int l = n , r = m;
        string toReturn;
        while(l > 0 and r > 0){
            if(str1[l-1] == str2[r-1]){
                toReturn.push_back(str1[l-1]);
                l = l-1, r = r-1;
            }
            else{
                dp[l-1][r] > dp[l][r-1]?l = l-1:r = r-1;
            }
        }
        reverse(toReturn.begin(),toReturn.end());
        int i = 0, j = 0;
        string res = "";
        for (char c : toReturn) {
            while (str1[i] != c)
                res += str1[i++];
            while (str2[j] != c)
                res += str2[j++];
            res += c, i++, j++;
        }
        return res + str1.substr(i) + str2.substr(j);
        
    }
};