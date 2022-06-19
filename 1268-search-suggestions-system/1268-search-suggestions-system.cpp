class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord) {
        int n = products.size();
        sort(products.begin(), products.end());  // Sort by increasing lexicographically order of products
        vector<vector<string>> ans;
        auto beginSearch = products.begin();
        int insertIndex = 0;
        string prefix = "";
        for (char &c : searchWord) {
            prefix += c;
            beginSearch = lower_bound(beginSearch, products.end(), prefix);
            insertIndex = beginSearch - products.begin();
            ans.push_back({});
            for (int i = insertIndex; i < min(insertIndex + 3, n); ++i) {
                if (products[i].find(prefix) != -1) {
                    ans.back().push_back(products[i]);
                }
            }
        }
        return ans;
    }
};