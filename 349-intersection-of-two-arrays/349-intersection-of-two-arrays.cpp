class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
//         unordered_set<int>s;
//         for(auto it:nums1)s.insert(it);
//         for(auto it:nums2){
//             auto f = s.find(it);
//             if(f!=s.end()){
//                 ans.push_back(it);
//                 s.erase(it);
//             }
//         }
        
//         return ans;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i1 = 0, i2 = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        while(i1<n1 and i2<n2){
            if(nums1[i1] == nums2[i2]){
                ans.push_back(nums1[i1]);
                i1++,i2++;
            }
            else if(nums1[i1]<nums2[i2]){
                i1++;
            }
            else i2++;
            while(i1>0 and i1<n1 and nums1[i1] == nums1[i1-1])i1++;
            while(i2>0 and i2<n2 and nums2[i2] == nums2[i2-1])i2++;
        }
        return ans;
    }
};