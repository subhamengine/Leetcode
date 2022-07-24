class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int x = 0, y = n-1;
        
        while(x >= 0 and x < m and y >= 0 and y < n){
            int ele = matrix[x][y];
            if(ele == target) return true;
            if(ele < target){
                x++;
            }else{
                y--;
            }
        }
        return false;
    }
};