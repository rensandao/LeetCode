#ifndef ADD_TWO_NUMBERSII_H
#define ADD_TWO_NUMBERSII_H

struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
};

//declaration for head insert method 
ListNode* HeadInsert(int sum, ListNode* res);

namespace lcpp {
	class Solution445_1 {
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
	};
}

#endif // ADD_TWO_NUMBERSII_H
