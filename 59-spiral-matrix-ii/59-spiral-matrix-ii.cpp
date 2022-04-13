class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>v(n,vector<int>(n,0));
        int r1 = 0, r2 = n-1, c1 = 0, c2 = n-1, val = 0;
        while(r1<=r2 and c1<=c2){
            //moving left to right, row fixed
            for(int i = c1 ; i<= c2 ; i++){
                v[r1][i] = ++val;
            }
            //moving top to bottom, column fixed
            for(int i = r1+1 ; i <= r2 ; i++){
                v[i][c2] = ++val;
            }
            if(r1<r2 and c1<c2){
                //moving right to left, row fixed
                for(int i = c2-1 ; i > c1 ; i--){
                    v[r2][i] = ++val;
                }
                //moving bottom to up, column fixed
                for(int i = r2 ; i > r1 ; i--){
                    v[i][c1] = ++val;
                }
            }
            r1++,r2--,c1++,c2--;
        }
        return v;
    }
};