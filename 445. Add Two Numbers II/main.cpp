#include <iostream>
#include "AddTwoNumbersII.h"

using namespace lcpp;

int main() {
	//initialize list 
	ListNode *l1 = nullptr, *l2 = nullptr, *res;
	l1 = HeadInsert(3, l1);
	l1 = HeadInsert(4, l1);
	l1 = HeadInsert(2, l1);
	l1 = HeadInsert(7, l1);

	l2 = HeadInsert(4, l2);
	l2 = HeadInsert(6, l2);
	l2 = HeadInsert(5, l2);

	std::cout << "Initialization using HeadInsert is ok!" << std::endl;

	//test
	ListNode* t1 = l1;
	while(t1) {
		std::cout << t1->val << std::endl;
		t1 = t1->next;
	}

	Solution445_1 s;
	res = s.addTwoNumbers(l1, l2);

	//test
	ListNode* temp = res;
	while (temp) {
		std::cout << temp->val << std::endl;
		temp = temp->next;
	}
	return 0;
}

