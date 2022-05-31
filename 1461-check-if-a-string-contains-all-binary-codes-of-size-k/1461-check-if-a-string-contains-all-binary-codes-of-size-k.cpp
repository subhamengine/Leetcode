class Solution {
public:
    unordered_set<string>st;
    bool hasAllCodes(string s, int k) {
        if(k > s.size()) return false;
        for (int i = 0; i <= s.size()-k; i++) {
            st.insert(s.substr(i,k));
        }
        return st.size() == pow(2,k);
        
    }
};