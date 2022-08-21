class Solution {
public:
    
    int fetch(string target, string stamp){
        for(int i = 0 ; i <= target.size() - stamp.size() ; i++){
            int j = 0;
            int s = i;
            bool nonStar = false;
            while(j < stamp.size() && s < target.size() && (target[s] == '*' || (target[s] == stamp[j]))){
                
                if(target[s] != '*') nonStar = true;
                s++;
                j++;
            }
            if(j == stamp.size() and nonStar){
                return i;
            }
            
        }
        return -1;
    }
    
    void update(string &target, int i, int st){
        for(int j = 0 ; j < st ; j++){
            target[j+i] = '*';
        }
    }
    
    vector<int> movesToStamp(string stamp, string target) {
        vector<int>ans;
        int len = target.size();
        int stSize = stamp.size();
        string targetStr(len,'*');
        
        while(target != targetStr){
            int stampIndex = fetch(target,stamp);
            if(stampIndex < 0){
                return {};
            }
            else{
                update(target,stampIndex,stSize);
            }
            ans.push_back(stampIndex);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};