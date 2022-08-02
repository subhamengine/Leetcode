class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int,vector<int>>pq;
        for(auto it:matrix){
            for(auto gt:it){
                pq.push(gt);
                if(pq.size()>k)pq.pop();
            }
        }
        // while(pq.size()>1){
        //     pq.pop();
        //     cout<<pq.top()<<endl;
        // }
        return pq.top();
    }
};