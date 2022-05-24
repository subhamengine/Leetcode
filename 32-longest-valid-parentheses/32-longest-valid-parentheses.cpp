class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        stack<int>st;
        st.push(-1);
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '('){
                st.push(i);
            }
            else{
                st.pop();
                if(!st.empty()){
                    int len = i - st.top();
                    ans = max(ans,len);
                }else{
                    st.push(i);
                }
            }
        }
        return ans;
    }
};