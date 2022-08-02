class Solution {
public:
    int rankCount(vector<vector<int>>& matrix, int target){
        int n = matrix.size();
        int i = n-1 , j = 0, count = 0;
        while(i>=0 and j < n){
            if(matrix[i][j] > target){
                i--;
            }
            else{
                count = count + i + 1;
                j++;
            }
        }
        return count;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), l = matrix[0][0], h = matrix[n-1][n-1];
        while(l<h){
            int mid = l + (h - l)/2;
            int count = rankCount(matrix,mid);
            if(count < k) l = mid+1;
            else h = mid;
        }
        return l;
    }
};