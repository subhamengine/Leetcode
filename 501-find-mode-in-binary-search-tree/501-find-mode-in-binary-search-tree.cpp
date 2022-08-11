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
    unordered_map<int,int>mp1;
    unordered_map<int,vector<int>>mp2;
    
    void help(TreeNode* root){
        if(!root) return;
        help(root->left);
        mp1[root->val]++;
        help(root->right);
        
    }
    
    vector<int> findMode(TreeNode* root) {
        help(root);
        for(auto it:mp1){
            mp2[it.second].push_back(it.first);
        }
        int maxi = 0;
        for(auto it:mp2){
            maxi = max(maxi,it.first);
        }
        vector<int>ans;
        for(auto it:mp2[maxi]){
            ans.push_back(it);
        }
        return ans;
    }
};