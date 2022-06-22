class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long one = LONG_MIN, two = LONG_MIN, three = LONG_MIN;
        for(auto it:nums){
            if(it == one or it == two || it == three) continue;
            if(it > one){
                three = two;
                two = one;
                one = it;
            }
            else if(it > two){
                three = two;
                two = it;
            }
            else if(it > three){
                three = it;
            }
        }
        return three == LONG_MIN ? one : three;
    } 
};