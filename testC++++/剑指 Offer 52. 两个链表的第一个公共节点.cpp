//
//  剑指 Offer 52.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/27.
//

#include "剑指 Offer 52. 两个链表的第一个公共节点.hpp"
#include "common.h"

ListNode *_offer_52_repeat_testgetIntersectionNode(ListNode *headA, ListNode *headB) {

    
    ListNode *l = headA;
    ListNode *r = headB;
    
    
    while (l != r) {
        if (!l) {
            l = headB;
        }else{
            l = l->next;
        }
        if (!r) {
            r = headA ;
        }else{
            r = r->next;
        }
    }
    
    return l;
    }

void _offer_52_repeat_test()
{
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    
    ListNode node4(4);
    ListNode node5(5);
    
    ListNode node6(6);
    ListNode node7(7);
    
    
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node6;
    
    node4.next = &node5;
    node5.next = &node6;
    
    node6.next = &node7;
    
    ListNode *res =  _offer_52_repeat_testgetIntersectionNode(&node1,&node4);
    
    
}
