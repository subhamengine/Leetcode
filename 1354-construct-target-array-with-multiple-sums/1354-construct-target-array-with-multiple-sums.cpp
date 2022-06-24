class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int,vector<int>>pq;
        long sum = 0;
        int a;
        for(int a : target) {
            pq.push(a);
            sum+=a;
        }
        while(true){
            a = pq.top();
            pq.pop();
            sum-=a;
            if(a == 1 || sum == 1) return true;
            if(a < sum || sum == 0 || a%sum == 0) return false;
            a = a%sum;
            sum+=a;
            pq.push(a);
        }
    }
};