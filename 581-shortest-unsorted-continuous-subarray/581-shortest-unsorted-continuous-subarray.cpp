class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>temp = nums;
        sort(temp.begin(),temp.end());
        
        int l = 0 , r = nums.size()-1;
        while(l<nums.size() and (nums[l] == temp[l])){
            l++;
        }
        while(r>=0 and (nums[r] == temp[r])){
            r--;
        }
        return  l>=r ? 0 : r-l+1;
    }
};