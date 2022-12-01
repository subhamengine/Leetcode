class Solution {
public:
    int help(char c){
        return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'a' || c =='e' || c == 'i' || c == 'o' || c == 'u');
    }
    bool halvesAreAlike(string s) {
        int c1 = 0, c2 = 0;
        for(int i = 0 ; i < s.size()/2 ; i++){
            if(help(s[i]))c1++;
        }
        for(int i = s.size()/2 ; i < s.size() ; i++){
            if(help(s[i]))c2++;
        }
        return (c1==c2);
    }
};