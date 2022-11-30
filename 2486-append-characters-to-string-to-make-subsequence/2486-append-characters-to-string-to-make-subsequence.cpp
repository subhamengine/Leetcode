class Solution {
public:
    int appendCharacters(string s, string t) {
        int sptr = 0;
        int tptr = 0;
        
        while(sptr < s.size() && tptr < t.size()){
            if(s[sptr] == t[tptr]){
                sptr++, tptr++;
            }else{
                sptr++;
            }
        }
        return t.size()-tptr;
    }
};