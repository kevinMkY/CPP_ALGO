//
//  剑指 Offer 18.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/26.
//

#include "剑指 Offer 18. 删除链表的节点.hpp"
#include "common.h"

ListNode* _offer_18_repeat_testdeleteNode(ListNode* head, int val) {
    if (!head) {
        return head;
    }
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode *cur = dummy;
    ListNode *next;
    while (cur) {
        next = cur->next;
        if (next && next->val == val) {
            cur->next= next->next;
            break;
        }
        cur = next;
    }
    
    return dummy->next;
    }

ListNode* _offer_18_repeat_testdeleteNode3(ListNode* head, int val) {

    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *pre = dummy;
    ListNode *cur = head;
    while (cur) {
        if (cur->val != val) {
            pre->next = cur;
            pre = cur;
        }else{
            pre->next = nullptr;
        }
        cur = cur->next;
    }
    return dummy->next;
    }

void _offer_18_repeat_test()
{
    ListNode node1(4);
    ListNode node2(5);
    ListNode node3(1);
    ListNode node4(9);
    
    
    
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
//    node5.next = &node6;
//    node6.next = &node7;
    
    ListNode *res = _offer_18_repeat_testdeleteNode3(&node1,1);
    
}
