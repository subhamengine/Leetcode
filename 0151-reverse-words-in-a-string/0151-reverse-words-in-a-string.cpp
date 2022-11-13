class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int i = 0, l = 0 , r = 0, n = s.size();
        while(i < n){
            while(i < n && s[i] != ' '){
                s[r++] = s[i++];
            }
            if(l < r){
                reverse(s.begin()+l,s.begin()+r);
                if(r == n) break;
                s[r++] = ' ';
                l = r;
            }
            ++i;
        }
         if (r > 0 && s[r-1] == ' ') --r;
        s.resize(r);
        return s;
    }
};