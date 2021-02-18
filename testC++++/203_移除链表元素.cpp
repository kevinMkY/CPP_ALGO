//
//  203_移除链表元素.cpp
//  testC++++
//
//  Created by ykh on 2020/9/9.
//

#import "203_移除链表元素.hpp"
#import "common.h"

//删除链表中等于给定值 val 的所有节点。
//
//示例:
//
//输入: 1->2->6->3->4->5->6, val = 6
//输出: 1->2->3->4->5
//https://leetcode-cn.com/problems/remove-linked-list-elements/

//输入: 1->2->6->3->4->5->6, val = 6
//输出: 1->2->3->4->5

// {1,ad_2} {2,ad_3} {3,ad_4} {4,ad_5}


//递归
ListNode* removeElements(ListNode* head, int val) {
    
    if (head == nullptr){
        return nullptr;
    }
    
    head->next = removeElements(head->next, val);
    
    if (head->val == val) {
        return head->next;
    }else{
        return head;
    }
}

//哨兵节点
ListNode* removeElements2(ListNode* head, int val) {
    ListNode temp = ListNode(0);
    temp.next = head;
    
    ListNode *pre = &temp;
    ListNode *cur = head;
    
    while (cur != nullptr) {
        if (cur->val == val) {
            pre->next = cur->next;
        }else{
            pre = cur;
        }
        cur = cur->next;
    }
    
    ListNode *res = temp.next;
    return res;
}

//遍历
ListNode* removeElements3(ListNode* head, int val) {
    if (head == nullptr) {
        return head;
    }
    
    ListNode *newHead = nullptr;
    ListNode *newLast = nullptr;
    ListNode *cur = head;
    while (cur) {
        if (cur->val!=val) {
            if (newHead == nullptr) {
                newHead = cur;
            }else{
                newLast->next = cur;
            }
            newLast = cur;
        }
        cur=cur->next;
    }
    if (newLast) {
        newLast->next = nullptr;
    }
    
    return newHead;
    
}

//递归
ListNode* removeElements4(ListNode* head, int val) {
    if (head == nullptr) {
        return head;
    }
    
    ListNode *next = removeElements4(head->next, val);
    if (head->val == val) {
        return next;
    }else{
        head->next = next;
        return head;
    }
}

//虚拟头节点
ListNode* removeElements5(ListNode* head, int val) {
    if (head == nullptr) {
        return head;
    }
    
    ListNode *newHead = new ListNode(0);
    ListNode *newTail = newHead;
    
    while (head) {
        if (head->val!=val) {
            newTail->next = head;
            newTail=head;
        }
        head = head->next;
    }
    newTail->next = nullptr;
    return newHead->next;
}


void _203_test()
{
    
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(6);
    ListNode node4(3);
    ListNode node5(4);
    ListNode node6(5);
    ListNode node7(6);
    
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
    node6.next = &node7;
    
    ListNode *nodeRes = removeElements5(&node1, 6);
    
}
