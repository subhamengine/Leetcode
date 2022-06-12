class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum = 0;
        int ans = INT_MIN;
        vector<int>map(1e4+7,-1);
        int start = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(map[nums[i]] == -1){
                sum+=nums[i];
            }
            else{
                ans = max(ans,sum);
                if(map[nums[i]] >= start){
                    int acc = accumulate(nums.begin()+start,nums.begin()+map[nums[i]]+1,0);
                    cout<<acc<<" ";
                    sum-=acc;
                    sum+=nums[i];
                    start = map[nums[i]]+1;
                }
                else sum+=nums[i];
            }
            
            map[nums[i]] = i;
        }
        return max(ans,sum);
    }
};