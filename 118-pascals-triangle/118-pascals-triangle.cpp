class Solution {
public:
    vector<vector<int>> generate(int n) {
        if( n == 1) return {{1}};
        vector<vector<int>>num;
        num = {{1},{1,1}};
        if(n == 2) return num;
        for(int i = 2 ; i < n ; i++){
            vector<int>vec;
            for(int j = 0 ; j <= i ; j++){
                if(j > 0 and j < i){
                    vec.push_back(num[i-1][j-1] + num[i-1][j]);
                }else vec.push_back(1);
            }
            num.push_back(vec);
        }
        return num;
    }
};