class Solution {
public:
    int solve(string s,string t){
        int n = s.size(), m = t.size();
        vector<int>num1(26,0);
        
        
        for(int i = 0 ; i < n ; i++){
            num1[s[i]-'a'] = true;
        }
        for(int j = 0 ; j < m ; j++){
            if(num1[t[j] - 'a'] == true) return 0;
        }
        return n*m;
    }
    
    
    int maxProduct(vector<string>& words) {
        int ans = 0;
        for(int i = 0 ; i < words.size() ; i++){
            for(int j = i+1 ; j < words.size() ; j++){
                ans = max(ans,solve(words[i],words[j]));
            }
        }
        return ans;
    }
};