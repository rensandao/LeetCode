/************************
Source:
Author: rensandao
First created： 2018-12-27
*************************/
#include "AddTwoNumbers.h"

using namespace lcpp;

/*190326
昨天先做了题445，利用相同方法，回头来看比较繁琐。是一种时间换空间方式，AD结果蛮高。
思路1：利用链长度和移位
1. 对应相加的sum利用头插法插入新的链表。
2. 由于头插法带来顺序问题，需要两次反转操作；
3. 解决carry进位问题。
*/

//190326 
//36ms, 98.89% faseter, 12.4MB
ListNode* Solution002_1::addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *res = nullptr, *ptr1 = l1, *ptr2 = l2;
	//1.add two
    while (ptr1 || ptr2) {
        int sum = 0;
        if (ptr1) { sum += ptr1->val; ptr1 = ptr1->next; }
        if (ptr2) { sum += ptr2->val; ptr2 = ptr2->next; }

        res = HeadInsert(sum, res);
    }
	//2.inverse res
    ptr1 = res; res = nullptr;
    while (ptr1) {
        res = HeadInsert(ptr1->val, res);
        ptr2 = ptr1;
        ptr1 = ptr1->next;
        delete ptr2;
    }
	//3.handle the carry 
    ptr1 = res; res = nullptr;
    int carry = 0, sum1 = 0;
    while (ptr1) {
        sum1 = (ptr1->val + carry) % 10;
        carry = (ptr1->val + carry) / 10;
        res = HeadInsert(sum1, res);

        ptr2 = ptr1;
        ptr1 = ptr1->next;
        delete ptr2;
    }
    if (carry) res = HeadInsert(1, res);
	//4.inverse res agagin.
    ptr1 = res; res = nullptr;
    while (ptr1) {
        res = HeadInsert(ptr1->val, res);
        ptr2 = ptr1;
        ptr1 = ptr1->next;
        delete ptr2;
    }

    return res;
}

//head insert func
ListNode* HeadInsert(int sum, ListNode* res) {
    ListNode* temp = new ListNode(sum);
    temp->next = res;
    return temp;
}
