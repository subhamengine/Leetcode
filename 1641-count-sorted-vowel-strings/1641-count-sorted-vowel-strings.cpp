class Solution {
public:
    unordered_map<char,int>mp;
    void solve(vector<char>&arr , int n , int &v , char prev){
        if(n == 0){
            v++;
            return;
        }
        for(int i = mp[prev] ; i < 5 ; i++){
            prev = arr[i];
            solve(arr,n-1,v,prev);
        }
    }
    int countVowelStrings(int n) {
        mp.insert({'a',0});
        mp.insert({'e',1});
        mp.insert({'i',2});
        mp.insert({'o',3});
        mp.insert({'u',4});
        int v = 0;
        vector<char>arr = {'a','e','i','o','u'};
        string curr = "";
        solve(arr,n,v,'a');
        
        return v;
    }
};