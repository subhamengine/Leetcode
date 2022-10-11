class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int c1 = INT_MAX;
        int c2 = INT_MAX;
        
        for(auto it:nums){
            if(it <= c1){
                c1 = it;
            }
            else if(it <= c2){
                c2 = it;
            }
            else return true;
        }
        return false;
    }
};