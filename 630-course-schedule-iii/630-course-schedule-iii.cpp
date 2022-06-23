class Solution {
public:
    static bool comp(vector<int>&a , vector<int>&b){
        if(a[1] == b[1]){
            return (a[1] < b[1]);
        }
        return (a[1] < b[1]);
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),comp);
        priority_queue<int,vector<int>>pq;
        int curr = 0;
        
        for(auto it:courses){
            if(it[0] <= it[1]){
                if(curr + it[0] <= it[1]){
                    curr+=it[0];
                    pq.push(it[0]);
                }
                else{
                    if(pq.top() > it[0]){
                        curr-=pq.top();
                        pq.pop();
                        pq.push(it[0]);
                        curr+=it[0];
                    }
                }
            }
        }
        return pq.size();
    }
};