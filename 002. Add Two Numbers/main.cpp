#include <iostream>
#include "AddTwoNumbers.h"

using namespace lcpp;

//reference
ListNode *new_linkedlist(std::initializer_list<int> lst)
{
    auto iter = lst.begin();
    ListNode *head = lst.size() ? new ListNode(*iter++) : NULL;
    for (ListNode *cur=head; iter != lst.end(); cur=cur->next)
        cur->next = new ListNode(*iter++);
    return head;
}

int main()
{
    Solution002_1 s;
    ListNode *l1 = new_linkedlist({2,4,3});
    ListNode *l2 = new_linkedlist({5,6,4});
    ListNode *ret = s.addTwoNumbers(l1, l2);
    
    for (ListNode *cur = ret; cur; cur = cur->next)
        std::cout << cur->val << "->";
    std::cout << "\b\b  " << std::endl;

    return 0;
}
