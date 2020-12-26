//
//  206_反转链表.cpp
//  testC++++
//
//  Created by ykh on 2020/9/9.
//

#import "206_反转链表.hpp"
#import "common.h"

//反转一个单链表。
//
//示例:
//
//输入: 1->2->3->4->5->NULL
//输出: 5->4->3->2->1->NULL
//进阶:
//你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/reverse-linked-list
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

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
