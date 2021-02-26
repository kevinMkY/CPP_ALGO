//
//  剑指 Offer 22.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/25.
//

#include "剑指 Offer 22. 链表中倒数第k个节点.hpp"
#include "common.h"

ListNode* _offer_22_repeat_test_getKthFromEnd(ListNode* head, int k) {
    
    if (!head || !head->next) {
        return head;
    }
    
    ListNode *slow = head;
    ListNode *fast = head->next;
    
    int n = 1;
    //1-2-3-4
    while (fast) {
        slow = slow->next;
        fast = fast->next;
        n++;
        if (fast) {
            fast = fast->next;
            if (!fast || !fast->next) {
                break;
            }else{
                n++;
            }
        }
    }
    
    //slow为中点
    
    
    return nullptr;
    }

ListNode* _offer_22_repeat_test_getKthFromEnd2(ListNode* head, int k) {
    
    if (!head || !head->next) {
        return head;
    }
    
    ListNode *pre = head;
    ListNode *cur = head;
    while (cur) {
        cur = cur->next;
        if (k > 0) {
            k--;
        }else{
            pre = pre->next;
        }
    }
    
    return pre;
    }


ListNode* _offer_22_repeat_test_getKthFromEnd3(ListNode* head, int k) {
    
    if (!head) {
        return head;
    }
    
    ListNode *cur = head;
    ListNode *slow = head;
    for (int i = 0; i < k; i++) {
        cur = cur->next;
        if (!cur) {
            return slow;
        }
    }
    
    while (cur) {
        slow = slow->next;
        cur = cur->next;
    }
    
    return slow;
    
}

void _offer_22_repeat_test()
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
    
    ListNode *res = _offer_22_repeat_test_getKthFromEnd3(&node1,2);
    
}
