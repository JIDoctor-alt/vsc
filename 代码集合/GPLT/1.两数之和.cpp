#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};
class Solution{
    public:
        ListNode* removeDuplicateNodes(ListNode* head){
            ListNode* ob = head;
            while(ob != nullptr){
                ListNode* oc = ob;
                while(oc->next != nullptr){
                    if(oc->next->val == ob->val){
                        oc->next = oc->next->next;
                    }else{
                        oc = oc->next;
                    }
                }
                ob = ob->next;
            }
            return head;
        }
};