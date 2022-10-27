class Solution {
public:
    int overlap(vector<vector<int>>& img1, vector<vector<int>>& img2, int row, int col){
        int count = 0;
        for(int r = 0 ; r<img1.size() ; r++){
            for(int c = 0 ; c < img1[0].size() ; c++){
                if((r+row < 0) || (r+row)>=img1.size() || (c+col < 0) || c+col>=img1.size()) continue;
                if(img1[r][c] + img2[r+row][c+col] == 2) count++;
            }
        }
        
        
        return count;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int ans = 0;
        int n = img1.size();
        
        for(int row = -n+1 ; row < n ; row++){
            for(int col = -n+1 ; col < n ; col++){
                ans = max(ans,overlap(img1,img2,row,col));
            }
        }
        return ans;
    }
};