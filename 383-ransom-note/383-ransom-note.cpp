class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>mp1;
        for(auto it:magazine){
            mp1[it]++;
        }
        for(auto it:ransomNote){
            mp1[it]--;
        }
        for(auto it:mp1){
            if(it.second < 0) return false;
        }
        return true;
    }
};