class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        multimap<float,pair<int,int>>mp;
        for(vector<int> it:points){
            int x1 = it[0], y1 = it[1];
            float dist = sqrt(pow((x1 - 0),2) + pow((y1 - 0),2));
            mp.insert({dist,{x1,y1}});
        }
        vector<vector<int>>ans;
        for(auto it : mp){
            if(!k) break;
            k--;
            vector<int>temp;
            temp.push_back(it.second.first);
            temp.push_back(it.second.second);
            ans.push_back(temp);
        }
        return ans;
    }
};