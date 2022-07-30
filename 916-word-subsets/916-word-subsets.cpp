class Solution {
public:
    vector<int> freq(string s){
        vector<int>frec(26,0);
        for(auto it:s){
            frec[it-'a']++;
        }
        return frec;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;
        vector<int>maxFreqCount(26,0);
        
        for(auto it:words2){
            vector<int>f = freq(it);
            for(int i = 0 ; i < 26 ; i++){
                maxFreqCount[i] = max(maxFreqCount[i],f[i]);
            }
        }
        for(auto it:words1){
            vector<int>f = freq(it);
            bool flag = true;
            for(int i = 0 ; i < 26 ; i++){
                if(f[i]<maxFreqCount[i]){
                    flag = false;
                }
            }
            if(flag)ans.push_back(it);
        }
        return ans;
    }
};