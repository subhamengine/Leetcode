class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int>minR(n);
        vector<int>maxL(n);
        for(int i = n-1 , mini = INT_MAX ; i >= 0 ; i--)minR[i]=mini=min(mini,nums[i]);
        for(int j = 0 , maxi = INT_MIN ; j < n ; j++)maxL[j]=maxi=max(maxi,nums[j]);
        
        int i = 0, j = n-1;
        while(i<n and nums[i]<=minR[i]) i++;
        while(j > i and nums[j] >= maxL[j])j--;
        
        return j-i+1;
    }
};