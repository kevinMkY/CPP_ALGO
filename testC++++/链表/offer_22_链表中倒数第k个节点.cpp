//
//  offer_22_链表中倒数第k个节点.cpp
//  testC++++
//
//  Created by ykh on 2020/9/11.
//

#include "offer_22_链表中倒数第k个节点.hpp"
#include "common.h"

//输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。例如，一个链表有6个节点，从头节点开始，它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个节点是值为4的节点。
//
// 
//
//示例：
//
//给定一个链表: 1->2->3->4->5, 和 k = 2.
//
//返回链表 4->5.
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// 1->2->3->4->5, 和 k = 2.   5+1-k = 5+1-2=4

// 1->2和 k = 1. 2+1-k=2+1-1=2

ListNode* getKthFromEnd(ListNode* head, int k) {

    if (head == nullptr) {
        return head;
    }
    
    int size = 1;
    
    ListNode *next = head->next;
    
    while (next != nullptr) {
        size++;
        next = next->next;
    }
    
    int targetIndex = size + 1 - k;
    next = head;
    if (targetIndex >= 0) {
        for (int i = 1; i < targetIndex; i++) {
            next = next->next;
        }
        return next;
    }else{
        return nullptr;
    }
    
    
}

void _offer_22_test(){
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);
    ListNode node6(3);
    ListNode node7(4);
    
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
//    node5.next = &node6;
//    node6.next = &node7;
    
    ListNode *nodeRes = getKthFromEnd(&node1,2);
    
}

