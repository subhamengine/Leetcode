class Solution {
public:
    bool binSearch(int ele, vector<int>& t, vector<bool>&vis){
        int l = 0, r = t.size()-1;
        int ans = -1;
        while(l <= r){
            int mid = r-(r-l)/2;
            if(t[mid] >= ele and vis[mid] == false){
                ans = mid;
                r = mid-1;
                
            }
            else l = mid+1;
        }
        if(ans == -1 )return false;
        else vis[ans] = true;
        return true;
    }
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int n = trainers.size();
        vector<bool>vis(n,false);
        int ans = 0;
        for(auto it:players){
            if(binSearch(it,trainers,vis) == true){
                ans++;
            }
        }
        return ans;
    }
};