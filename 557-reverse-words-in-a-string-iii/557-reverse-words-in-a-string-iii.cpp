class Solution {
public:
    string reverseWords(string s) {
        string word;
 
        // making a string stream
        stringstream iss(s);
        string ans="";
        // Read and print each word.
        while (iss >> word){
            reverse(word.begin(),word.end());
            ans+=word;
            ans+=" ";
        }
        ans.pop_back();
        
    return ans;
    }
};