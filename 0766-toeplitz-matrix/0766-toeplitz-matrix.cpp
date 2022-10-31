class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& m) {
        for(int i = 1 ; i < m.size() ; i++){
            for(int j = 1 ; j < m[0].size() ; j++){
                if(m[i-1][j-1] != m[i][j]) return false;
            }
        }
        return true;
    }
};