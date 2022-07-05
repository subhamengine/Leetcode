class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(auto it:nums){
            st.insert(it);
        }
        int maxlen = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            int num = nums[i];
            if(st.find(num-1) == st.end()){
                int len = 1;
               while(st.find(num+1) != st.end()){
                   len++;
                   num++;
               }
                maxlen = max(maxlen,len);
            }
            
        }
        return maxlen;
    }
};