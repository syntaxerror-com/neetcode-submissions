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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      
      ListNode* curr = head;
      int size = 0;

      while(curr != NULL){
        curr = curr->next;
        size++;
      }

      int k = size - n;

      // deleting head node
      if(k == 0){
        return head->next;
      }

      curr = head;
      ListNode *prev = curr;
      int a = 0;

      while(a != k){
        prev = curr;
        curr = curr->next;
        a++;
      }

      prev->next = curr->next;

      return head;
    }
};