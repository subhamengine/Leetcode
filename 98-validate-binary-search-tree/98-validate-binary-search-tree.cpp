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
    bool help(TreeNode* root, double l, double r){
        if(!root) return true;
        if((root->left and root->left->val >= root->val) or (root->right and root->right->val <= root->val)) return false;
        if(root->val < l or root->val > r) return false;
        
        return help(root->left,l,(double)root->val-1) and help(root->right,(double)root->val+1,r);
        return true;
    }
    bool isValidBST(TreeNode* root) {
        double  l = pow(-2,31);
        double r = pow(2,31)-1;
        return help(root,l,r);
    }
};