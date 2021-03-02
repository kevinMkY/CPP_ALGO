//
//  _142_环形链表 II.cpp
//  testC++++
//
//  Created by mm on 2021/3/2.
//

#include "_142_环形链表 II.hpp"
#include "common.h"


ListNode *detectCycle(ListNode *head) {
        
    if (!head || !head->next) {
        return nullptr;
    }
    
    ListNode *slow = head;
    ListNode *fast = head;
    bool startCount = false;
    int count = 0;
    while (fast) {
        slow = slow->next;
        if (startCount) {
            count++;
        }
        fast = fast->next;
        if (fast) {
            fast = fast->next;
            if (fast ) {
                if (fast == slow) {
                    if (!startCount) {
                        startCount = true;
                    }else{
                        break;
                    }
                }
            }else{
                return nullptr;
            }
        }else{
            return nullptr;
        }
    }
    
    slow = head;
    fast = head;
    
    for (int i = 0; i<count; i++) {
        fast = fast->next;
    }
    
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    
    return fast;
    }


void _142_test()
{

    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(0);
    ListNode node4(-4);
//    ListNode node5(5);
    
    node1.next = &node2;
//    node2.next = &node3;
    node3.next = &node4;    
    node4.next = &node2;
    
    ListNode *res= detectCycle(&node1);

}
