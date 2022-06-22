class Solution {
public:
    void set(vector<vector<int>>& matrix , int curRow, int curCol){
        for(int i = 0 ; i < matrix[curRow].size()  ; i++){
            
            matrix[curRow][i] = 0;
        }
        for(int i = 0 ; i < matrix.size() ; i++){
            
            matrix[i][curCol] = 0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        multimap<int,int>mp;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < matrix[i].size() ; j++){
                if(matrix[i][j] == 0){
                    mp.insert({i,j});
                }
            }
        }
        for(auto it:mp){
            set(matrix,it.first,it.second);
        }
        
    }
};