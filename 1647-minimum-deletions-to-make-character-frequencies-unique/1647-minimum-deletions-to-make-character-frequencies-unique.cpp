class Solution {
public:
    int minDeletions(string s) {
        unordered_map<int,int>charcnt;
        unordered_map<int,int>uniquefreq;
        int count=0;
        
        for(int i=0;i<s.size();i++)
        {
            charcnt[s[i]-'a']++;
        }
        
        for(auto &it : charcnt)
        {
            int x= it.second;
            if(uniquefreq[x]!=0)
            {
                while(x>0 && uniquefreq[x]!=0)
                {
                    x--;
                    count++;
                }
            }
            if(x>0)
            {
                uniquefreq[x]++;
            }
        }
        
        return count;
    }
};