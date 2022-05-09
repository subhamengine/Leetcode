class Solution {
public:
   vector<string>list;
    unordered_map<char,string>mp;
    
    void backTracking(int i, string &curStr,string &digits){
        if(curStr.size() == digits.size()){
            list.push_back(curStr);
            return;
        }
        for(char ch : mp[digits[i]]){
            curStr.push_back(ch);
            backTracking(i+1,curStr,digits);
            curStr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        mp.insert({'2',"abc"});
        mp.insert({'3',"def"});
        mp.insert({'4',"ghi"});
        mp.insert({'5',"jkl"});
        mp.insert({'6',"mno"});
        mp.insert({'7',"pqrs"});
        mp.insert({'8',"tuv"});
        mp.insert({'9',"wxyz"});
        
        string curStr = "";
        backTracking(0,curStr,digits);
        
        if(digits.size())return list;
        return {};
    }
};