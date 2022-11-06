class Solution {
public:
    string orderlyQueue(string s, int k) {
        string ans = s;
        if(k == 1){
            string org = s.substr(1,s.size()-1);
            org.push_back(s[0]);
            
            while(org != s){
                ans = min(ans,org);
                string org1 = org.substr(1,org.size()-1);
                org1.push_back(org[0]);
                org = org1;
            }
        }
        else sort(ans.begin(),ans.end());
        
        return ans;
    }
};