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
    
    
    void solve(TreeNode* &ans,TreeNode* root){
        if(!root)return;
        solve(ans,root->left);
        ans->right = new TreeNode(root->val);
        ans = ans->right;
        solve(ans,root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(!root)return root;
        TreeNode* dummy = new TreeNode();
        TreeNode* temp  = dummy;
        solve(dummy,root);
        return temp->right;
        
    }
};