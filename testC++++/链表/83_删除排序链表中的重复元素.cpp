//
//  83_删除排序链表中的重复元素.cpp
//  testC++++
//
//  Created by ykh on 2020/9/9.
//

#include "83_删除排序链表中的重复元素.hpp"
#include "common.h"

//https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/

ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode *pre = head;
    ListNode *cur = head->next;
    while (cur != nullptr) {
        if (pre->val == cur->val) {
            pre->next = cur->next;
        }else{
            pre = cur;
        }
        cur = cur->next;
    }
    return head;
}

void _83_test(){

    ListNode node1(1);
    ListNode node2(1);
    ListNode node3(2);
    ListNode node4(2);
    ListNode node5(3);
    ListNode node6(3);
    ListNode node7(4);
    
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
    node6.next = &node7;
    
    ListNode *nodeRes = deleteDuplicates(&node1);
    
}
