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

/****************************************************************************************************************************************
181227
思路1：迭代。
1）要确定头结点；
2）进入循环，如何确定“独立无二”的解？当有duplicates时，先选择这个相同部分的最后一个值，再进入一个循环判断。最关键的判断是，
通过判断要返回的主链中末尾结点prev->next是否等于当前结点指针，有说明中间有重复的，没有则说明当前结点“独一无二”。

结论：
做链表的题要有几条参考原则：
1）一个主链时刻不能断；
2）单链表，逆向没有线索。知道当前结点，不能推出前驱结点。本题中就需要更新前驱结点的下一个，也即当前唯一的结点。
****************************************************************************************************************************************/
class Solution1 {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) return head;
        
        ListNode A(INT_MIN);
        A.next = head;
        ListNode *prev = &A;
        
        while (prev->next) {  //判断循环条件是根据主链的末尾指针prev->next
            ListNode *cur = prev->next; //初始化下一个潜在结点指针
            while (cur->next && cur->next->val == cur->val)  cur = cur->next; //找到duplicates最后一个
            if (cur != prev->next)  
                prev->next = cur->next;
            else  
                prev = prev->next;
        }        
        return (&A)->next;
    }
};
