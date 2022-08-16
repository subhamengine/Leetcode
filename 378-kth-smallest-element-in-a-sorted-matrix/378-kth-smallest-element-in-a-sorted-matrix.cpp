class Solution {
public:
    
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), l = matrix[0][0], h = matrix[n-1][n-1];
        while(l<h){
            int mid = l + (h - l)/2;
            int count = 0;
            for(int i = 0 ; i < n ; i++){
                count+= upper_bound(matrix[i].begin() , matrix[i].end() , mid) - matrix[i].begin();
            }
            cout<<mid <<" -> "<<count<<endl;
            if(count < k) l = mid+1;
            else h = mid;
        }
        return l;
    }
};