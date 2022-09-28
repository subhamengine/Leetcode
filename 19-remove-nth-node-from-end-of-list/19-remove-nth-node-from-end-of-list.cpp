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
    ListNode* rev(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nex;
        
        while(curr){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == NULL) return NULL;
        head = rev(head);
        if(n == 1){
            head = head->next;
            return rev(head);
        }
        ListNode* prev = NULL;
        ListNode* curr=head;
        ListNode* nex;
        while(--n){
            nex=curr->next;
            prev=curr;
            curr=nex;
        }
        prev->next = curr->next;
        return rev(head);
    }
};