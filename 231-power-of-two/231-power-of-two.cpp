class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <=1) return n==1;
        return (n%2 == 0) and isPowerOfTwo(n/2);
        
    }
};