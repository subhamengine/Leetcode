class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>>store(26);
        for(int i = 0 ; i < s.size() ; i++ ){
            store[s[i]-'a'].push_back(i);
        }
        int res = 0;
        for(auto word:words){
            bool found = true;
            int x = -1;
            for(auto ch : word){
                auto it = upper_bound(store[ch-'a'].begin(),store[ch-'a'].end(),x);
                if(it == store[ch-'a'].end()){ found = false; break;}
                else x = *it;
                
            }
            if(found) res++;
        }
        return res;
    }
};