class Solution {
public:
    void sortme(int r , int c , vector<vector<int>>&mat){
        vector<int>arr;
        int p = r, q = c;
        while(r < mat.size() and c < mat[0].size()){
            int x = mat[r][c];
            arr.push_back(x);
            r++;
            c++;
        }
        sort(arr.begin(),arr.end());
        int i = 0;
        while(p < mat.size() and q < mat[0].size()){
            mat[p][q] = arr[i];
            i++;
            p++;
            q++;
        }
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        for(int i = 0 ; i < r ; i++){
            sortme(i,0,mat);
        }
        for(int i = 1 ; i < c ; i++){
            sortme(0,i,mat);
        }
        return mat;
    }
};