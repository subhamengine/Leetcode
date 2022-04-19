class Solution {
public:
    string digitSum(string s, int k) {
        
        while(s.length()>k){
            string newString = "";
            int len = s.length();
            int num = 0;
            int j = 0;
            for(int i = 0 ; i < len ; i++){
                num+=(int)s[i] - 48;
                ++j;
                if(j==k){
                    newString+=to_string(num);
                    j = 0;
                    num = 0;
                }
            }
            if(j>0) newString+=to_string(num);
            
            s = newString;
        }
        return s;
    }
};