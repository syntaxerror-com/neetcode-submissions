class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* a = new ListNode(0);
        ListNode* curr = a;

        ListNode* curr1 = list1;
        ListNode* curr2 = list2;

        while(curr1 != NULL && curr2 != NULL) {

            if(curr1->val >= curr2->val) {
                a->next = curr2;
                curr2 = curr2->next;
            }
            else {
                a->next = curr1;
                curr1 = curr1->next;
            }

            a = a->next;
        }

        if(curr1 == NULL) {
            a->next = curr2;
        }
        else {
            a->next = curr1;
        }

        return curr->next;
    }
};