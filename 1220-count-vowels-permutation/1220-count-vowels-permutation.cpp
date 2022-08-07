class Solution {
public:
    int countVowelPermutation(int n) {
        long a,e,i,o,u, mod = pow(10,9)+7;
        a = e = i = o = u = 1;
        long a2,e2,i2,o2,u2;
        for(int j = 2 ; j <= n ; j++){
            a2 = (e + i + u)%mod;
            e2 = (a + i)%mod;
            i2 = (e + o)%mod;
            o2 = i;
            u2 = (i + o)%mod;
            a = a2, e = e2 , i = i2 , o = o2, u = u2;
        }
        return (a + e + i + o + u)%mod;
    }
};