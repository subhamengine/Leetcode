class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        map<int,int>mp;
        int num = 0;
        for(auto it:nums){
            mp[it]++;
            if(mp[it] == 2){
                num = it;
               
            }
        }
        vector<int>ans;
        ans.push_back(num);
        int i = 1;
        for( i = 1; i <= *max_element(nums.begin(),nums.end()) ;i++){
            if(mp.find(i) == mp.end()){
                ans.push_back(i);
                break;
            }
        }
        if(ans.size() == 1){
            ans.push_back(i);
        }
        return ans;
    }
};