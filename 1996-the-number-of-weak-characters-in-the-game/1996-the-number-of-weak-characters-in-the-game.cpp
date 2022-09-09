class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& prop) {
        int count = 0, diff = INT_MIN;
        
        sort(prop.begin(),prop.end(),[](const auto &a, const auto &b){
            return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
        });
        
        for(auto it:prop){
            count+=it[1] < diff;
            diff = max(diff,it[1]);
        }
        return count;
        
    }
};