class Solution {
public:
    int solve(vector<int>& nums){
        int n = nums.size();
        if(n==1)return nums[0];
        int ptr1 = nums[0];
        int ptr2 = max(nums[0],nums[1]);
        
        for(int i = 2 ; i < n ; i++){
            int newNum = max(nums[i] + ptr1 , ptr2);
            ptr1 = ptr2;
            ptr2 = newNum;
        }
        return ptr2;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int>a(nums.begin(),nums.end()-1);
        vector<int>b(nums.begin()+1,nums.end());
        return (max(solve(a),solve(b)));
    }
};