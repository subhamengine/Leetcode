class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        sort(tasks.begin(),tasks.end());
        int ans = 0;
        int n = tasks.size();
        int last = -1;
        for(int i = 0 ; i < n ; i++){
            int curCount = 0;
            
            while(i<n-1 and tasks[i] == tasks[i+1]){
                i++;
                
            }
            curCount = i-last;
            last = i;
            while(curCount){
                if(curCount <= 1)return -1;
                else{
                    while(curCount>=3){
                        curCount = curCount-3;
                        ans++;
                    }
                    if(curCount) ans+=1;
                    curCount = 0;
                }
            }
        }
        return ans;
    }
};