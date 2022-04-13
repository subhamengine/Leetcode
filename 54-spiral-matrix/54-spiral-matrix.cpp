class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int r1 = 0, r2 = n-1, c1 = 0, c2 = m-1;
        vector<int>v;
        while(r1<=r2 and c1<=c2){
            for(int i = c1 ; i <= c2 ; i++){
                v.push_back(matrix[r1][i]);
            }
            for(int i = r1+1 ; i <= r2 ; i++){
                v.push_back(matrix[i][c2]);
            }
            if(r1<r2 and c1<c2){
                for(int i = c2-1 ; i> c1 ; i--){
                    v.push_back(matrix[r2][i]);
                }
                for(int i = r2 ; i > r1 ; i--){
                    v.push_back(matrix[i][c1]);
                }
            }
            r1++,r2--,c1++,c2--;
        }
        return v;
    }
};