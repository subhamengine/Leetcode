class Solution {
public:
    string reverseWords(string s) {
        string word;
        string ans = "";
        stringstream iss(s);

        vector<string>temp;
        while (iss >> word){
            temp.push_back(word);
        }
        
        reverse(temp.begin(),temp.end());
        for(auto it:temp){
            ans+=it;
            ans+=" ";
        }
        ans.pop_back();
        return ans;
    }
};