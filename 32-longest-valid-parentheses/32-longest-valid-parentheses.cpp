class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        int c, o;
        c = 0, o = 0;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == ')') c++;
            else o++;
            if(o == c){
                int len = o*2;
                ans = max(ans,len);
            }
            else if(c > o){
                c = o = 0;
            }
        }
        c = o = 0;
        for(int i = s.size()-1 ; i >= 0 ; i--){
            if(s[i] == ')') c++;
            else o++;
            if(o == c){
                int len = o*2;
                ans = max(ans,len);
            }
            else if(c < o){
                c = o = 0;
            }
        }
        return ans;
    }
};