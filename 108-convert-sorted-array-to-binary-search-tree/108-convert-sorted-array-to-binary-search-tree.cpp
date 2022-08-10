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
    TreeNode* help(int l, int r,vector<int>&nums){
        if(l>r){
            return NULL;
        }
        int mid = (l+r)/2;
        TreeNode* toadd = new TreeNode(nums[mid]);
        toadd->left = help(l,mid-1,nums);
        toadd->right = help(mid+1,r,nums);
        return toadd;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = new TreeNode(0);
        int n = nums.size();
        
        return help(0,n-1,nums);
    }
};