class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string temp = to_string(n);
        unordered_map<int,int>mp;
        set<long long>st;
        for(auto it:temp){
            mp[it]++;
        }
        int len = temp.size();
        for(long long i = 1 ; i < pow(10,len+1) ; i =(long long) i*(long long)2){
            string s = to_string(i);
            if(s.size() == len) st.insert(i);
        }
        
        for(auto it:st){
            string str = to_string(it);
            unordered_map<int,int>mp1 = mp;
            bool flag = true;
            for(auto gt:str){
                mp1[gt]--;
                if(mp1[gt] < 0) flag = false;
            }
            if(flag == false) continue;
            else{
                for(auto gt:mp1){
                    if(gt.second > 0) {
                        flag = false;
                        break;
                    }
                }
            }
            if(flag == true) return true;
        }
        return false;
    }
};