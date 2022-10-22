class Solution {
public:
     string minWindow(string s, string t) {
        unordered_map<char, int> letters; //unordered map for storing the characters in t that we need to check for in s
        for(auto c : t) letters[c]++; 
        int count = 0; //counts number of t's letters in current window
        int low = 0, min_length = INT_MAX, min_start = 0;     
        for(int high = 0; high<s.length(); high++) {
            if(letters[s[high]] > 0) count++; //means that this letter is in t   
            letters[s[high]]--; //reduce the count for the letter on which we are currently 
            if(count == t.length()) { //if current windows contains all of the letters in t
                while(low < high && letters[s[low]] < 0) letters[s[low]]++, low++; //move low ahead if its not of any significance
                if(min_length > high-low) min_length = high-(min_start=low)+1; //update the min length
                letters[s[low++]]++; //move low ahaead and also increment the value
                count--; //count-- as we are moving low ahead & low pointed to a char in t before
            }
        }
        return min_length == INT_MAX ? "" : s.substr(min_start, min_length); //check for edge case & return the result
    }
};