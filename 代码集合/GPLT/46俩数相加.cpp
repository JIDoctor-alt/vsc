#include <iostream>
using namespace std;

struct ListNode {
    int val;
  ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* head = new ListNode(-1);
       ListNode* h = head;
       int sum = 0;
       bool carry = false;
       while(l1 != nullptr || l2 != nullptr)
       {
           sum = 0;
           if(l1 != nullptr)
           {
               sum += l1->val;
               l1 = l1->next;
           }
           if(l2 != nullptr)
           {
               sum += l2->val;
               l2 = l2->next;
           }

           if(carry)
                sum++;
           h->next = new ListNode(sum%10);
           h = h->next;
           carry = sum >= 10 ? true : false;
       }
       if(carry)
       {
           h->next = new ListNode(1);
       }
       return head->next;
    }
};