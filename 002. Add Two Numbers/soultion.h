/************************
Source:
Author: rensandao
First created： 2018-12-27
*************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
/*
181228
思路1： 迭代。
可挖掘的信息有： 1）需要考虑到有进位和两链表不同长短。2)
步骤：
1）只有两链表的下一结点有一个部位不为空，则继续运算：若链表1不为空，则数值1为结点数据，否则为0；
同理，链表2不为空为结点的值，否则为0。(这里可以用三目运算来表示，简洁）
主链辅助指针后移一位。
2)对于两链上结点求相加的个位数和进位数大小；

需要注意的是，最后循环结束的仍得考虑一次进位问题。

Reference: 灵魂机器PDF
*/
//
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
    }
}
