class Solution {
public:
    int mod = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_map<int,long>mp;
        for(int i = 0 ; i < arr.size() ; i++){
            long count = 1;
            for(int j = 0 ; j < i ; j++){
                if((arr[i]%arr[j] == 0) and mp.find(arr[i]/arr[j])!=mp.end()){
                    count+=(mp[arr[j]] * mp[arr[i]/arr[j]])%mod;
                }
            }
            mp.insert({arr[i],count});
        }
        long sum = 0;
        for(auto it:mp){
            sum= (sum+it.second)%mod;
        }
        return sum%mod;
    }
};