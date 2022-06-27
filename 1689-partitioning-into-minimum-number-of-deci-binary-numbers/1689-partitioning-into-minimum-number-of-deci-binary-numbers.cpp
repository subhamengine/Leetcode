class Solution {
public:
    int minPartitions(string n) {
        int m = 0;
        for(auto it:n){
            m = max(m,it-'0');
        }
        return m;
    }
};