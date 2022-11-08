class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        
        while(true){
            unordered_set<int>st;
            for(int i = 1 ; i < s.size() ;i++ ){
                if(  abs(s[i]-s[i-1]) == 32){
                    cout<<i-1<<" "<<i<<" ";
                    st.insert(i);
                    st.insert(i-1);
                    i++;
                    
                }
            }
            if(st.size()==0) return s;
            else{
                string t = "";
                for(int i = 0 ; i < s.size() ; i++){
                    if(st.find(i)==st.end()){
                        t+=s[i];
                    }
                }
                s = t;
            }
            cout<<s<<endl;
        
        }
        return s;
        
        
    }
};