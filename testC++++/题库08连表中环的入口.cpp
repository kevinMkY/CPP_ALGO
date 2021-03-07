//
//  题库08连表中环的入口.cpp
//  testC++++
//
//  Created by yekaihua on 2021/3/6.
//

#include "题库08连表中环的入口.hpp"
#include "common.h"

ListNode *_tk_08_test_detectCycle(ListNode *head) {
        
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                break;
            }
        }
        
        if(!fast || !fast->next) return nullptr;
        
        slow = head;
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        
        return fast;
    }

void _tk_08_test()
{
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(0);
    ListNode node4(-4);
//    ListNode node5(5);
    
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node2;
    
    ListNode *res= _tk_08_test_detectCycle(&node1);
    
}
