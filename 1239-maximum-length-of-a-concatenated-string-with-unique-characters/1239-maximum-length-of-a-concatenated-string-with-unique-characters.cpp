class Solution {
public:
    int len = 0;
    
    int maxLength(vector<string>& arr) {
        check("",arr,0);
        return len;
    }
    void check(string s, vector<string>&arr, int itr){
        if(!help(s))return;
        if (s.size() > len) len = s.size();
        for(int i = itr ; i < arr.size() ; i++){
            check(s+arr[i], arr, i+1);
        }
    }
    bool help(string s){
        set<char>st;
        for(auto it:s){
            if(st.find(it) != st.end()) return false;
            st.insert(it);
        }
        return true;
    }
};