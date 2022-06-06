/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* slow = headA;
        ListNode* fast = headB;
        
        
        if(!slow or !fast) return NULL;
        while(slow and fast and slow != fast){
            
            slow = slow->next;
            fast = fast->next;
            if(slow == fast) return slow;
            
            if(!slow) slow = headA;
            if(!fast) fast = headB;
        }
        return slow;
    }
};