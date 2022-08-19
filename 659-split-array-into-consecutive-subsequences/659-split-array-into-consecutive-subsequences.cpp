class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> left, end;
        
        for(auto it:nums) left[it]++;
        
        for(auto it:nums){
            if(left[it] == 0) continue;
            left[it]--;
            
            if(end[it-1] > 0){
                end[it-1]--;
                end[it]++;
            }else if(left[it+1] > 0 and left[it+2] > 0){
                left[it+1]--;
                left[it+2]--;
                end[it+2]++;
            }
            else return false;
        }
        return true;
    }
};