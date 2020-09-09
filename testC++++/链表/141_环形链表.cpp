//
//  3_环形链表.cpp
//  testC++++
//
//  Created by ykh on 2020/9/9.
//

#include "141_环形链表.hpp"
#include "common.h"

//https://leetcode-cn.com/problems/linked-list-cycle/

//判断有环,用快慢指针

bool hasCycle(ListNode *head) {
    
    if (head == nullptr || head->next == nullptr) {
        return false;
    }
    
    ListNode *slow = head;
    ListNode *fast = head->next;
    ListNode *middle = nullptr;
    
    while (fast != nullptr) {
        if (slow == fast) {
            return true;
        }
        slow = slow->next;
        middle = fast->next;
        if (middle == nullptr) {
            break;
        }
        fast = fast->next->next;
    }
    
    return false;
}

void _141_test()
{
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node2;
    
    bool res = hasCycle(&node1);
    
}
