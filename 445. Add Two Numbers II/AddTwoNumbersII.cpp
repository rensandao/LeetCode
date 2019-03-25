/*************************************
Source:
Author: rensandao
First Created: 2018-12-28
**************************************/
/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 8 -> 0 -> 7

#include "AddTwoNumbersII.h"
#include <iostream>

using namespace lcpp;

/*190324
整体思路:
R1:
限制条件：不修改原链表的结构，不反转链表。
由于是单向链表，而数字的进位与链表的方向相反，这是问题的主要麻烦。

链表的基本操作有插入、删除、获得长度，获得指定元素等。
针对主要问题：
1.进位和链表线索方向相反，可以反转链表，但限制条件约束不改原链表结构。是否可以借助其他数据结构，如栈的FILO性质。
2.是否利用自身仅有的信息-两个链表的长度，作为突破口；

对于加法操作：
1.是否可以借助递归；
2.或是写成工具方便调用；

*/

//method1 
/*仅利用两链长度为突破口；
1.利用长度差信息和链表指针移位操作，先从链头到尾的顺序，对应位置数据相加，得到的结果（可能大于10）再采用头插法的方式，
构建成新的链表。现在的结果是反向顺序（即表头是个位数相加结果，靠近表尾是高位相加结果，同时进位问题没有处理）
2.对于构建的新的链表，处理大于10进位的问题。再采用头插法，解决上面的两个问题。
3.
*/
ListNode* Solution445_1::addTwoNumbers(ListNode* l1, ListNode* l2) {
	int len1 = 0, len2 = 0;
	ListNode *ptr1 = l1, *ptr2 = l2, *res = nullptr;

	//get each length for use
	while (ptr1) {
		ptr1 = ptr1->next;
		len1++;
	}
	while (ptr2) {
		ptr2 = ptr2->next;
		len2++;
	}

	//step1: strategy to operate addition
	ptr1 = l1; ptr2 = l2;
	while (len1 > 0 && len2 > 0) {
		int sum = 0;
		if (len1 >= len2) {
				sum += ptr1->val;
				ptr1 = ptr1->next;
				len1--;
		}
		if (len1 < len2) {
				sum += ptr2->val;
				ptr2 = ptr2->next;
				len2--;
		}
		res = HeadInsert(sum, res);
	}
	
	//step2: carry and inverse
	ptr1 = res; int carry = 0;
	ListNode* res1 = nullptr;
	while (ptr1) {
		int newVal = 0;
		newVal = (ptr1->val + carry) % 10;
		carry = (ptr1->val + carry) / 10;

		ptr2 = ptr1;
		ptr1 = ptr1->next;
		res1 = HeadInsert(newVal, res1);
		delete ptr2; //avoid memory leakage
	}
	if(carry > 0) {
		res1 = HeadInsert(1,res1);
	}
	return res1;
}

ListNode* HeadInsert(int sum, ListNode* res) {
	ListNode* temp = new ListNode(sum);
	temp->next = res;
	return temp;
}
