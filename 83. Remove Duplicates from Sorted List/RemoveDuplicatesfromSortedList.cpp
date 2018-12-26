/****************************************
Source:
Author: rensandao
First Creation: 2018-12-26
*****************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 /*
 181226
 思路：
 循环条件是根据当前结点是否为空指针。
 1.如果下一结点p指向的值等于当前结点指向的值，则当前结点指向下下个结点，下个结点指向为空（注意顺序不能反）。
 2.如果前后结点的值不等，则当前结点更新为下一结点。
 
 Runtime: 12ms, 42.64% faster.
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *cur = head;
        
        while(cur != NULL) {
            ListNode *p = cur->next;
            if(p==NULL) return head;
            
            if(p->val == cur->val) {
                cur->next = p->next;
                p->next = NULL;
            } else {
                cur = cur->next;    
            }
        }
        return head;
    }
};
