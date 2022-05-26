class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = __builtin_popcount(n);
        return count;
    }
};