class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        
        while(true){
            stack<char>st;
            for(int i = 0 ; i < s.size() ; i++){
                bool flag = false;
                while(!st.empty() and st.top() == s[i]){
                    st.pop();
                    flag = true;
                }
                if(flag == false) st.push(s[i]);
            }
            
            string temp="";
            while(!st.empty()){
                temp.push_back(st.top());
                st.pop();
            }
            reverse(temp.begin(),temp.end());
            if(temp == s) return s;
            s = temp;
            
        }
        return s;
    }
};