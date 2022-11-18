class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        for(int i = 0 ; i < nums.size() ; i++){
            while(!dq.empty() && nums[dq.front()] < nums[i]){
                dq.pop_front();
            }
            dq.push_front(i);
            
            while(!dq.empty() && dq.back() <= i-k)dq.pop_back();
            if(i-k+1 >= 0 && dq.back()>=i-k) ans.push_back(nums[dq.back()]);
        }
        return ans;
    }
};