class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        vector<int>dp(days[days.size()-1]+1,0);
        set<int>st;
        for(auto it:days)st.insert(it);
        
        for(int i = 1 ; i < dp.size() ; i++){
            int oneDay = dp[i-1];
            int sevenDay = 0, thirtyDay = 0;
            if(i-7 >= 0) {
                sevenDay = dp[i-7];
            }
            if(i - 30 >= 0){
                thirtyDay = dp[i-30];
            }
            if(st.count(i)){
                dp[i] = min(oneDay+cost[0],min(sevenDay+cost[1],thirtyDay+cost[2]));
            }else{
                dp[i] = dp[i-1];
            }
        }
        return dp[dp.size()-1];
    }
};