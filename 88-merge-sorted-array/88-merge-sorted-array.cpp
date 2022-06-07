class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0,counter  = 0;
        while(i<m && j<n){
            if(nums1[i]<nums2[j])
                i++;
            else if(nums2[j]<=nums1[i]){
                nums1.insert(nums1.begin()+i,nums2[j]);
                m++;
                counter++;
                j++;
            }
        }
        while(j<n){
            nums1[i++] = (nums2[j]);
            j++;
        }
        while(counter--){
            nums1.pop_back();
        }
    }
};