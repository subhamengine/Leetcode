class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == val){
                int k =0;
                while(i<nums.size() && nums[i] == val){
                    nums.erase(nums.begin()+i);
                    k++;
                    
                }
            }
        }
        return nums.size();
    }
};