class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        multiset<int>st;
        int ans = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            bool flag = false;
            auto it = st.find(k-nums[i]);
            if(it!=st.end()){
                ans++;
                st.erase(it);
                flag = true;
            }
            if(!flag)st.insert(nums[i]);
        }
        return ans;
    }
};