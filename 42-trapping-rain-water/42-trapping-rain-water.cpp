class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>v1(n);
        vector<int>v2(n);
        int prev = 0;
        for(int i = 0 ; i < n ; i++){
            prev = max(prev,height[i]);
            v1[i] = prev;
        }
        prev = 0;
        for(int i = n-1 ; i >= 0 ; i--){
            prev = max(prev,height[i]);
            v2[i] = prev;
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            ans+=(min(v1[i],v2[i]) - height[i]);
        }
        return ans;
    }
};