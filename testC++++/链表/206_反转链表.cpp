//
//  206_反转链表.cpp
//  testC++++
//
//  Created by ykh on 2020/9/9.
//

#include "206_反转链表.hpp"
#include "common.h"

//https://leetcode-cn.com/problems/reverse-linked-list/

//递归
ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    
    ListNode *newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

//非递归
ListNode* reverseList2(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    
    ListNode *newHead = nullptr;
    while (head != nullptr) {
        ListNode *tmp = head->next;
        head->next = newHead;
        newHead = head;
        head= tmp;
    }

    return newHead;
}

void _206_test(){
    
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    
    ListNode *nodeRes = reverseList2(&node1);
    
}
