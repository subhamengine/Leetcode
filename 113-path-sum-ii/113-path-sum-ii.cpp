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
    vector<vector<int>>ans;
    void help(TreeNode* root, vector<int>temp, int tSum){
        if(!root) return;
        tSum-=root->val;
        temp.push_back(root->val);
        if(tSum == 0 and root->left == NULL and root->right == NULL){
            
            ans.push_back(temp);
            return;
        }
        help(root->left,temp,tSum);
        help(root->right,temp,tSum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        help(root,temp,targetSum);
        return ans;
    }
};