class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        unordered_set<string>st;
        
        for(int i = 0 ; i < b.size() ; i++){
            for(int j = 0 ; j < b[0].size() ; j++){
                if(b[i][j] != '.'){
                    int boxNum = (i/3)*3+(j/3);
                    string row = to_string(b[i][j]) + " found at row " + to_string(i);
                    string col = to_string(b[i][j]) + " found at col " + to_string(j);
                    string box = to_string(b[i][j]) + " found at box " + to_string(boxNum);
                    
                    if(st.find(row)!=st.end() || st.find(col) != st.end() || st.find(box) != st.end()){
                        return false;
                    }
                    else{
                        st.insert(row);
                        st.insert(col);
                        st.insert(box);
                    }
                    
                }
            }
        }
        return true;
    }
};