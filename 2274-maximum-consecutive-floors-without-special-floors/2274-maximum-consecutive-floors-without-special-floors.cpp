class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        int n = special.size();
        int res = max(special[0] - bottom , top - special[n-1]);
        for(int i = 1 ; i < n ; i++){
            res = max(res,special[i] - special[i-1] - 1);
        }
        return res;
    }
};