class Solution {
public:
    int countTime(string time) {
        int ans = 1;
        if(time[0] == '?'){
            ans = time[1] == '?'?24:time[1] < '4'?3:2;
        }
        else if(time[1] == '?'){
            ans = time[0] < '2'?10:4;
        }
        return ans*(time[3] == '?'?6:1) * (time[4] == '?'?10:1);
    }
};