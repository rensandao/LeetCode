#include <iostream>
#include "AddTwoNumbers.h"

using namespace lcpp;

//reference
ListNode *new_linkedlist(std::initializer_list<int> list)
{
    auto iter = list.begin();
    ListNode *head = list.size() ? new ListNode(*iter++) : nullptr;
    for (ListNode *cur=head; iter != list.end(); cur=cur->next)
        cur->next = new ListNode(*iter++);
    return head;
}

int main()
{
    Solution002_1 s;
    ListNode *l1 = new_linkedlist({2,4,3});
    ListNode *l2 = new_linkedlist({5,6,4});
    ListNode *res = s.addTwoNumbers(l1, l2);
    
    for (ListNode *cur = res; cur; cur = cur->next)
        std::cout << cur->val << "->";
    std::cout << "\b\b  " << std::endl;

    return 0;
}
