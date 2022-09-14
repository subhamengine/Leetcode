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
    int result = 0;
    bool isPalin(vector<int>&arr){
        int odd = 0;
        for(int i = 1 ; i<= 9 ; i++){
            if(arr[i] % 2 != 0) odd++;
        }
        if(odd > 1) return false;
        return true;
    }
    void dfs(TreeNode* root, vector<int>&arr){
        if(!root) return;
        arr[root->val]++;
        if(root->left == NULL and root->right == NULL){
            if(isPalin(arr)){
                result++;
            }

        }
        else {
            dfs(root->left,arr);
            dfs(root->right,arr);
        }
        arr[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>arr(10,0);
        dfs(root,arr);
        return result;
    }
    
};