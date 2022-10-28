class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& t) {
        sort(nums.begin(),nums.end());
        sort(t.begin(),t.end());
        vector<int>evenNums,oddNums,evenT,oddT;
        
        for(auto it:nums){
            if(it%2 == 0){
                evenNums.push_back(it);
            }
            else{
                oddNums.push_back(it);
            }
        }
        for(auto it:t){
            if(it%2 == 0){
                evenT.push_back(it);
            }
            else{
                oddT.push_back(it);
            }
        }
        
        
        
        long long count = 0;
        for(int i = 0 ; i < evenNums.size() ; i++){
            int diff = abs(evenNums[i]-evenT[i]);
            count= count + (long long)(diff/2);
        }
        for(int i = 0 ; i < oddNums.size() ; i++){
            int diff = abs(oddNums[i]-oddT[i]);
            count= count + (long long)(diff/2);
        }
        
        return count/2;
    }
};