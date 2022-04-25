class Solution {
public:
    int arrangeCoins(int n) {
        int ans = 0;
        long long sum = 0;
        for(int i = 1 ; i <2e31 - 1 ; i++){
            sum = sum + i;
            ans++;
            if(sum>n)break;
        }
        return --ans;
    }
};