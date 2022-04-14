class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
       int l = 0, r = m-1;
        while(l<n and r<m and r>=0 and l>=0){
            if(matrix[l][r] == target)return true;
            else if(matrix[l][r]<target){
                l++;
            }else{
                r--;
            }
        }
        return false;
    }
};