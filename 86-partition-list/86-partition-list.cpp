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
            
            if(head->val < x){
                dummy1->next = head;
                dummy1 = dummy1->next;
            }
            else{
                dummy2->next = head;
                dummy2 = dummy2->next;
            }
            ListNode* temp = head->next;
            head->next = NULL;
            head = temp;
        }
        dummy1->next = right->next;
        return left->next;
    }
};