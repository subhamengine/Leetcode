class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* ptr1=head;
        int len=0;
        while(ptr1){
            len++;
            ptr1=ptr1->next;
        }
        ptr1=head;
        if(len & 1) len=len/2+1;
        else len=(len/2)+1;
        for(int i=1;i<len;i++){
            head=head->next;
        }
        return head;
    }
};