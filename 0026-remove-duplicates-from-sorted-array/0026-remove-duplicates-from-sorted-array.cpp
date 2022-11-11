class Solution {
public:
    int removeDuplicates(vector<int>& A) {
        int n = A.size();
        int count = 0;
        for(int i = 1; i < n; i++){
            if(A[i] == A[i-1]) count++;
            else A[i-count] = A[i];
        }
        return n-count;
    }
};