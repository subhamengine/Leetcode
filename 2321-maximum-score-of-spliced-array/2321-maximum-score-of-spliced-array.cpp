class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        
        int sum1 = accumulate(nums1.begin(),nums1.end(),0);
        int sum2 = accumulate(nums2.begin(),nums2.end(),0);
        int ans = max(sum1,sum2);
        
        int first = 0, second = 0, max1 = 0, max2 = 0;
        
        for(int i = 0 ; i < nums1.size() ; i++){
            first += (nums2[i] - nums1[i]);
            second += (nums1[i] - nums2[i]);
            max1 = max(max1,first);
            max2 = max(max2,second);
            if(first < 0) first = 0;
            if(second < 0) second = 0;
        }
        ans = max(ans,sum1+max1);
        ans = max(ans,sum2+max2);
        return ans;
    }
};