//
//  876_链表的中间节点.cpp
//  testC++++
//
//  Created by ykh on 2020/9/9.
//

#include "876_链表的中间节点.hpp"
#include "common.h"

//https://leetcode-cn.com/problems/middle-of-the-linked-list/


//两边循环
ListNode* middleNode(ListNode* head) {
    
    int num = 0;
    int secondNum = 0;
    ListNode *cur = head;
    while (cur != nullptr) {
        cur = cur->next;
        num++;
    }
    
    cur = head;
    while (cur != nullptr) {
        cur = cur->next;
        secondNum++;
        if (secondNum == num/2) {
            return cur;
        }
    }
    
    return head;
}

//快慢指针
ListNode* middleNode2(ListNode* head) {
    
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    
    ListNode *slow = head;
    ListNode *fast = head->next;
    ListNode *middle;
    
    while (fast != nullptr) {
        slow = slow->next;
        middle = fast->next;
        if (middle == nullptr) {
            return slow;
        }
        fast = fast->next->next;
    }
    
    return slow;
}

void _876_test(){
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);
    ListNode node6(6);
    ListNode node7(7);
    ListNode node8(8);
    
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
    node6.next = &node7;
//    node7.next = &node8;
    
    ListNode *nodeRes = middleNode2(&node1);
    
}
