

class Solution {
public:
   
    struct video{
    long sum = 0;
    string small;
    int max_view = 0;
};
    vector<vector<string>> mostPopularCreator(vector<string>& c, vector<string>& ids, vector<int>& views) {
        unordered_map<string, video> mp;
    long count = 0;

    for (int i = 0; i < size(c); i++){
	    // Check if creator present or not
        if (!mp.count(c[i])){
            mp[c[i]] = { views[i], ids[i], views[i] };
            count = max(count, mp[c[i]].sum);
            continue;
        }
    
	    // If already present , update all parameters as said in above algorithm
        mp[c[i]].sum += views[i];
        if (mp[c[i]].max_view < views[i] || mp[c[i]].max_view == views[i] && ids[i] < mp[c[i]].small) {
            mp[c[i]].max_view = views[i];
            mp[c[i]].small = ids[i];
        }

        count = max(count, mp[c[i]].sum);
    }

    //extract words with highest count of views
    vector<vector<string>> ans;
    for (auto &r: mp)
        if (r.second.sum == count)
            ans.push_back({ r.first, r.second.small });

    return ans;
    }
};