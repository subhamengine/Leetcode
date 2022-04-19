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
    void solve(TreeNode* root, TreeNode* &prev, TreeNode* &first , TreeNode* &last){
        if(!root)return;
        solve(root->left,prev,first,last);
        if(prev){
            if(prev->val > root->val){
                if(!first){
                    first = prev;
                }
                last = root;
            }
        }
        prev = root;
        solve(root->right,prev,first,last);
    }
    void recoverTree(TreeNode* root) {
        TreeNode* prev = NULL, *first = NULL, *last = NULL;
        solve(root,prev,first,last);
        swap(first->val,last->val);
    }
};