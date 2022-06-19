#### [2. 两数相加](https://leetcode.cn/problems/add-two-numbers/)

> 头结点、尾节点、尾插法、lamda表达式、取余操作、构造函数

```c++
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
class Solution{
    public :
     ListNode* addTwoNumbers(ListNode* l1,ListNode* l2){
        ListNode *head = nullptr,*tail = nullptr;
        int carry = 0;
      

        while(l1 || l2){
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carry;
            if(!head){
                head = tail = new ListNode((sum%10));
               
            }else{
                tail->next = new ListNode((sum%10));
                tail = tail->next;
            }

            if(l1){
                l1 = l1->next;
            }
            if(l2){
                l2 = l2->next;
            }

            carry = sum/10;
        }
        if(carry > 0){
            tail->next = new ListNode(carry);
        }
        return head;
     }
};
```

#### [3. 无重复字符的最长子串](https://leetcode.cn/problems/longest-substring-without-repeating-characters/)

> 双指针：左指针右移，右指针右移；左指针右移时去除哈希表中的字符，右指针右移添加到哈希表中

```c++

```

