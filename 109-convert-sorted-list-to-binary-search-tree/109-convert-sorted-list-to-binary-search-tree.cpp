/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head, ListNode* tail = NULL) {
        if(head == tail) return NULL;
        ListNode* s = head;
        ListNode* f = head;
        
        while(f!=tail and f->next!=tail){
            s = s->next;
            f = f->next->next;
        }
        
        TreeNode* root = new TreeNode(s->val);
        root->left = sortedListToBST(head,s);
        root->right = sortedListToBST(s->next,tail);
        return root;
    }
};