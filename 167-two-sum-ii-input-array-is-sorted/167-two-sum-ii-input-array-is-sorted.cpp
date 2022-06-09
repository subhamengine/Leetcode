class Solution {
public:
    int search(int target, vector<int>&nums, int i){
        int j = nums.size()-1;
        while(i<=j){
            int mid = (i+j)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target){
                i = mid+1;
            }
            else j = mid-1;
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& nums, int tar) {
        int n = nums.size();
        for(int i = 0 ; i < nums.size() ; i++){
            int num = nums[i];
            int nextNumIndex = search(tar-num,nums,i+1);
            if(nextNumIndex != -1){
                return {i+1,nextNumIndex+1};
            }
        }
        return {};
    }
};