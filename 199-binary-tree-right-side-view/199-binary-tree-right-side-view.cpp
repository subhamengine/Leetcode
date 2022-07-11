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
    map<int,int>mp;
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int>ans;
        queue<pair<int,TreeNode*>>q;
        q.push({0,root});
        int r = 0;
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            mp.insert({t.first,t.second->val});
            
            if (t.second->right != NULL)
                q.push({t.first+1,t.second->right});
            
            if (t.second->left != NULL)
            q.push({t.first+1 , t.second->left,});
 
            
            
            
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};