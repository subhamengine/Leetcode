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
    vector<int>ans;
    int cursor = INT_MIN, curfre = 0, maxfre = 0;
    void help(TreeNode* root){
        if(!root) return;
        help(root->left);
        
        if(cursor == root->val) curfre ++;
        else curfre = 1;
        
        if(curfre > maxfre){
            ans.clear();
            maxfre = curfre;
            ans.push_back(root->val);
        }
        else if(curfre == maxfre){
            ans.push_back(root->val);
        }
        
        cursor = root->val;
        help(root->right);
        
    }
    
    vector<int> findMode(TreeNode* root) {
        help(root);
        
        return ans;
    }
};