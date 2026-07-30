class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast->next != NULL && fast->next->next != NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
       ListNode* prev = NULL;
       ListNode* curr=slow->next;
       slow->next = NULL;

       while(curr!=NULL){
           ListNode* next = curr->next;
           curr->next = prev;
           prev = curr;
           curr = next;
       }  
       ListNode* first = head;
       curr= prev;
     
        while (curr != NULL) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = curr->next;

            first->next = curr;
            curr->next = temp1;

            first = temp1;
            curr = temp2;
        }
    }
};
