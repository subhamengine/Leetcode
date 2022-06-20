class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        for(auto &it:words){
            reverse(it.begin(),it.end());
        }
        sort(words.begin(),words.end());
        int res = 0;
        for(int i = 0 ; i < words.size() - 1 ; i++){
            res += words[i] == words[i+1].substr(0,words[i].size()) ? 0:words[i].size()+1;
        }
        return (res+words[words.size()-1].size()+1);
    }
};