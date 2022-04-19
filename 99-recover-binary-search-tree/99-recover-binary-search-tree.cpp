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
    void solve(TreeNode* root, vector<int>&v){
        if(!root)return;
        solve(root->left,v);
        v.push_back(root->val);
        solve(root->right,v);
    }
    int i = 0;
    void solve2(TreeNode* root,vector<int>v){
        if(!root)return;
        solve2(root->left,v);
        root->val = v[i];
        i++;
        solve2(root->right,v);
    }
    void recoverTree(TreeNode* root) {
        vector<int>v;
        solve(root,v);
        sort(v.begin(),v.end());
        solve2(root,v);
       
    }
};