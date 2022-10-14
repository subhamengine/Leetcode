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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* prev = head;
        if(!head or !head->next) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next and fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast->next != NULL) slow = slow->next;
        // cout<<slow->val<<" "<<fast->val;
        while(prev and prev->next!=slow){
            prev = prev->next;
        }
        
        prev->next = slow->next;
        slow->next = NULL;
        return head;
    }
};