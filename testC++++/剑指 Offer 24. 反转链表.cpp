//
//  剑指 Offer 24.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/26.
//

#include "剑指 Offer 24. 反转链表.hpp"
#include "common.h"

ListNode* _offer_24_repeat_testreverseList(ListNode* head) {

    if (!head || !head->next) {
        return head;
    }
    
    ListNode *newheader = nullptr;
    ListNode *next = nullptr;
    //new = 0
    //h = 1
    //n = 2
    //
    while (head) {
        next = head->next;
        head->next = newheader;
        newheader = head;
        head = next;
    }
    
    return newheader;
   }

ListNode* _offer_24_repeat_testreverseList2(ListNode* head) {

    if (!head || !head->next) {
        return head;
    }
 
    ListNode *next = _offer_24_repeat_testreverseList2(head->next);
    ListNode *tmp = next;
    while (tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = head;
    head->next = nullptr;
    
    return next;
   }


void _offer_24_repeat_test()
{
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);
    
    
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
//    node5.next = &node6;
//    node6.next = &node7;
    
    ListNode *res = _offer_24_repeat_testreverseList2(&node1);
    
}
