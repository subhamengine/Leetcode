class Solution {
public:
    int s1,s2,s3,s4;
    bool help(vector<int>&nums,int i){
        if(i == nums.size()){
            if(s1 == 0 and s2 == 0 and s3 == 0 and s4 == 0) return true;
            else return false;
        } 
        if(nums[i]<=s1){
            s1-=nums[i];
            if(help(nums,i+1)) return true;
            s1+=nums[i];      
        }
        if(nums[i] <= s2){
            s2-=nums[i];
            if(help(nums,i+1)) return true;
            s2+=nums[i];
        }
        if(nums[i] <= s3){
            s3-=nums[i];
            if(help(nums,i+1)) return true;
            s3+=nums[i];
        }
        if(nums[i] <= s4){
            s4-=nums[i];
            if(help(nums,i+1)) return true;
            s4+=nums[i];
        }
        return false;
    }
    bool makesquare(vector<int>& m) {
        int sum = accumulate(m.begin(),m.end(),0);
        if(sum%4 != 0) return false;
        sort(m.rbegin(),m.rend());
        
        s1 = s2 = s3 = s4 = sum/4;
       
        return help(m,0);
    }
};