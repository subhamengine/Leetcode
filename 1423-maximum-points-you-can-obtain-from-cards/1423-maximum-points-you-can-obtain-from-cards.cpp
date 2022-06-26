class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int ptr = 0;
        int sum = 0;
        int tSum = accumulate(card.begin(),card.end(),0);
        int total = tSum;
        if(card.size() == k) return total;
        int windowSize = card.size()-k;
        for(int i = 0 ; i < card.size() ; i++){
            sum+=card[i];
            if(i-ptr+1 == windowSize){
                tSum = min(tSum,sum);
                sum-=card[ptr];
                ptr++;
            }
        }
        return total-tSum;
    }
};