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
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* left = new ListNode(0);
        ListNode* right = new ListNode(0);   
        ListNode* dummy1 = left;
        ListNode* dummy2 = right;
        
        while(head){
            ListNode* upcoming = new ListNode(head->val);
            if(head->val < x){
                dummy1->next = upcoming;
                dummy1 = dummy1->next;
            }
            else{
                dummy2->next = upcoming;
                dummy2 = dummy2->next;
            }
            head = head->next;
        }
        dummy1->next = right->next;
        return left->next;
    }
};