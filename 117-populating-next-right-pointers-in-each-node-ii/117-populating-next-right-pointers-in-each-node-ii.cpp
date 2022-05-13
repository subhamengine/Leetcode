/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    void help(Node* root, int level , unordered_map<int,vector<Node*>>&mp){
        if(root == NULL) return;
        help(root->left,level+1,mp);
        mp[level].push_back(root);
        help(root->right,level+1,mp);
    }
    Node* connect(Node* root) {
        int level = 0;
        unordered_map<int,vector<Node*>>mp;
        help(root,level,mp);
        for(auto it:mp){
            vector<Node*>&v = it.second;
            for(int i = 0 ; i < v.size()-1 ; i++){
                v[i]->next = v[i+1];
            }
            v[v.size()-1]->next = NULL;
        }
        
        return root;
    }
};