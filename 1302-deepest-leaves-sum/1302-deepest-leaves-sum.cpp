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
    void solve(TreeNode* root, int curLevl , int &level){
        if(!root) return;
        solve(root->left,curLevl+1,level);
        if(curLevl > level)level = curLevl;
        solve(root->right,curLevl+1,level);
    }
    void sumUp(TreeNode* root, int &sum, int curLevel , int &level){
        if(!root)return;
        sumUp(root->left,sum,curLevel+1,level);
        if(level == curLevel)sum+=root->val;
        sumUp(root->right,sum,curLevel+1,level);
    }
    int deepestLeavesSum(TreeNode* root) {
        int level = 0;
        solve(root,0,level);
        int sum = 0;
        sumUp(root,sum,0,level);
        return sum;
    }
};