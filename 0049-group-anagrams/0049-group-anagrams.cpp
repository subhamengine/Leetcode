class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(string it:strs){
            string gt = it;
            sort(gt.begin(),gt.end());
            mp[gt].push_back(it);
        }
        vector<vector<string>>vec;
        for(auto it:mp){
            vector<string>temp;
            for(auto gt:it.second){
                temp.push_back(gt);
            }
            vec.push_back(temp);
            
        }
        return vec;
    }
};