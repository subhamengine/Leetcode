class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0;
        vector<unordered_map<int,int>>maps(nums.size());
        
        for(int i = 1 ; i < maps.size() ; i++){
            for(int j = 0 ; j < i ; j++){
                long cd = (long)nums[i]-(long)nums[j];
                if(cd <= INT_MIN || cd >= INT_MAX) continue;
                int apsEndingOnJ = maps[j][cd];
                int apEndingOnI = maps[i][cd];
                ans+=apsEndingOnJ;
                maps[i][(int)cd] = apsEndingOnJ + apEndingOnI+1;
            }
        }
        
        return ans;
    }
};