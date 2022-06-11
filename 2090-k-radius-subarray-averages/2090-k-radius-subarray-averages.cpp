class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        int window = k*2+1;
        int p = 0;
        vector<int>res(n,-1);
        long long curSum = 0;
        for(int i = 0 ; i < n ; i++){
            curSum+=nums[i];
            if(i - p + 1 == window){
                if(i < n){
                    res[p+(window/2)] = curSum/(i-p+1);
                    curSum-=nums[p];
                    p++;
                }
            
            }
        }
        return res;
    }
};