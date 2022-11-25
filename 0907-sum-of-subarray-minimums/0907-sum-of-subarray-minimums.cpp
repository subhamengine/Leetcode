class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9+7;
        int ans = 0;
        
        stack<int>st;
        
        for(long i = 0 ; i <= n ; i++){
            while(!st.empty() && (i == n || arr[st.top()]>=arr[i])){
                int idx = st.top();
                st.pop();
                long right = i < n ? i - idx : n - idx;
                long left = st.empty() ? idx + 1 : idx - st.top();
                
                ans = (ans + left *right *arr[idx]) % mod;
            }
            st.push(i);
        }
        
        return ans;
    }
};