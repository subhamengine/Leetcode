class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int largest = n-1, mid = n-2, small = n-3;
        int p = 0;
        while(small >= 0){
            if(nums[largest] + nums[mid] > nums[small] && nums[mid] + nums[small] > nums[largest] && nums[largest]+nums[small] > nums[mid]){
                return nums[largest] + nums[mid] + nums[small];
            }
            else{
                largest--, small--, mid--;
            }
        }
        return p;
    }
};