class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        unordered_map<string,int>mp;
        int max_len = 0;
        for(auto st:dict){
            mp[st]++;
            max_len = max(max_len,(int)st.length());
        }
        string ans = "",temp;
        stringstream ss(sentence);
        while(ss>>temp){
            int len = temp.size();
            bool flag = false;
            for(int i = 1 ; i <= min(len,max_len) ; i++){
                if(mp.find(temp.substr(0,i)) != mp.end()){
                    ans += " " + temp.substr(0,i);
                    flag = true;
                    break;
                }
            }
            if(!flag){
                ans+=" "+temp;
            }
        }
        return ans.substr(1);
    }
};