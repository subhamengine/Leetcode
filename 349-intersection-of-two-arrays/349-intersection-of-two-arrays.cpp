class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_set<int>s;
        for(auto it:nums1)s.insert(it);
        for(auto it:nums2){
            auto f = s.find(it);
            if(f!=s.end()){
                ans.push_back(it);
                s.erase(it);
            }
        }
        
        return ans;
    }
};