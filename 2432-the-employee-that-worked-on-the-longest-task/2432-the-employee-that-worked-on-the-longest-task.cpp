class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
       int start = 0;
        int prevId = 0;
        int prevTime = 0;
        for(auto it:logs){
            int currTime = it[1] - start;
            int currId = it[0];
            start = it[1];
            if(currTime == prevTime){
                if(currId < prevId) {
                    prevId = currId;
                    
                }
            }else{
                if(currTime > prevTime){
                    prevId = currId;
                    prevTime = currTime;
                }
            }
        }
        return prevId;
    }
};