//
//  237_删除链表中的节点.cpp
//  testC++++
//
//  Created by ykh on 2020/9/9.
//

#include "237_删除链表中的节点.hpp"
#include "common.h"

//https://leetcode-cn.com/problems/delete-node-in-a-linked-list/




void deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}

void _237_test(){
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    
    deleteNode(&node3);
    
    
}
