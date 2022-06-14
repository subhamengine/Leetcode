class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size() , m = potions.size();
        sort(potions.begin(),potions.end());
        vector<int>ans(n,0);
        for(int i = 0 ; i < n ; i++){
            int minIndex  = INT_MAX;
            int l = 0 , r = m-1;
            int sp = spells[i];
            while(l<=r){
                int mid = l + (r-l)/2;
               
                if((long long int)sp *(long long int)potions[mid]  < success){
                    l = mid+1;
                }else{
                    minIndex = min(minIndex,mid);
                    r = mid-1;
                }
            }
            ans[i] = minIndex == INT_MAX ? 0 : m - minIndex;
        }
        return ans;
    }
};