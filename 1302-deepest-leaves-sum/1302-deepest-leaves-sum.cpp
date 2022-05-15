/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int level ,  map<int,vector<int>,greater<int>>&mp){
        if(!root)return;
        solve(root->left,level+1,mp);
        if(mp.size() and level > mp.begin()->first)mp.erase(mp.begin());
        mp[level].push_back(root->val);
        solve(root->right,level+1,mp);
    }
    int deepestLeavesSum(TreeNode* root) {
        map<int,vector<int>,greater<int>>mp;
        int level = 0;
        solve(root,level,mp);
        int ans = 0;
        for(auto it:mp){
            
            for(auto gt:it.second){
                ans+=gt;
                
            }
            
            break;
            
        }
        return ans;
    }
};