class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<pair<int,int>>p;
        for(int i = 0 ; i < nums.size() ; i++){
            p.push_back({nums[i],cost[i]});
        }
        
        sort(p.begin(),p.end());
        long long totalElements = 0;
        for(auto it:p){
            totalElements+=(long long)it.second;
        }
        long long median = 0,sum=0;
        int i = 0;
        while(sum<(totalElements+1)/2 && i < nums.size()){
            sum+=(long long)p[i].second;
            median = p[i].first;
            i++;
        }
        long long ans =0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] != median){
                ans+= (long long)abs(nums[i]-median)*(long long)cost[i];
            }
        }
        return ans;
    }
};