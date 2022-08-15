class Solution {
public:
    int romanToInt(string s) {
        int num = 0;
        unordered_map<char,int>mp;
        mp.insert({'I',1});
        mp.insert({'V',5});
        mp.insert({'X',10});
        mp.insert({'L',50});
        mp.insert({'C',100});
        mp.insert({'D',500});
        mp.insert({'M',1000});
        
        for(int i = 0 ; i < s.size() ; i++){
            if(i > 0){
                if(mp[s[i]] > mp[s[i-1]]){
                    num-=mp[s[i-1]];
                    num+= mp[s[i]] - mp[s[i-1]];
                }
                else{
                    num+=mp[s[i]];
                }
            }
            else{
                num+=mp[s[i]];
            }
        }
        return num;
    }
};