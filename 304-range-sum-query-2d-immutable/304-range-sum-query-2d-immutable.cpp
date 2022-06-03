class NumMatrix {
public:
    vector<vector<int>>mat;
    int row, col;
    NumMatrix(vector<vector<int>>& matrix) {
        row = matrix.size() , col = matrix[0].size();
        mat = vector<vector<int>>(row + 1 , vector<int>(col + 1 , 0));
        for(int i = 1; i <= row ; i++){
            for(int j = 1 ; j <= col ; j++){
                mat[i][j] = matrix[i-1][j-1] + mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1] ;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return mat[row2 + 1][col2 + 1] - mat[row2 + 1][col1] - mat[row1][col2+1] + mat[row1][col1]; 
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */