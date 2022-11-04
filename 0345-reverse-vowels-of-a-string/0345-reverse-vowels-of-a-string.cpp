class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size()-1;
        set<char>st={'a','e','i','o','u','A','E','I','O','U'};
        while(i < j){
            while(st.find(s[i])==st.end() && i < j ){
                i++;
            }
            while(st.find(s[j])==st.end() &&i<j){
                j--;
            }
            swap(s[i],s[j]);
            i++;
            j--;
        }
        return s;
    }
};