class Solution {
public:
    int countHousePlacements(int n) {
        vector<long long>dp(n+3);
        dp[0] = 0;
        dp[1] = 1;
        int m = 1e9 + 7;
        for(int i = 2 ; i <= n+2 ; i++){
            dp[i] = (dp[i-1])%m + (dp[i-2])%m;
        }
        return (dp[n+2])%m * (dp[n+2])%m;
    }
};