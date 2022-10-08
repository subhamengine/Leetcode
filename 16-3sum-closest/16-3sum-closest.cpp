class Solution {
public:
    
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3) return 0;
        sort(nums.begin(),nums.end());
        int close = nums[0] + nums[1] + nums[2];
        for(int i = 0 ; i < nums.size() ; i++){
            if(i>0 and nums[i] == nums[i-1]) continue;
            int num = nums[i];
            int l = i+1;
            int r = nums.size()-1;
            while(l<r){
                int sum = num + nums[l] + nums[r];
                if(sum == target) return target;
                if(abs(target-sum) < abs(target-close)){
                    close = sum;
                }
                if(sum > target){
                    r--;
                }
                else if(sum < target){  
                    l++;
                }
            }
        }
        return close;
    }
};