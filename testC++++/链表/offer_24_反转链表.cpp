//
//  offer_24_反转链表.cpp
//  testC++++
//
//  Created by ykh on 2020/9/11.
//

#include "offer_24_反转链表.hpp"
#include "common.h"

//定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
//
// 
//
//示例:
//
//输入: 1->2->3->4->5->NULL
//输出: 5->4->3->2->1->NULL
// 
//
//限制：
//
//0 <= 节点个数 <= 5000
//
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

ListNode* reverseList24(ListNode* head) {

    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    
    ListNode* newhead = nullptr;
    
    while (head !=nullptr) {
        ListNode *temp = head->next;
        head->next = newhead;
        newhead = head;
        head = temp;
    }
    
    return newhead;
    }

ListNode* reverseList25(ListNode* head) {

    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    
    ListNode* newhead = reverseList25(head->next);
    head->next->next = head;
    head->next = nullptr;
    
    return newhead;
    }

void _offer_24_test(){
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
    
    ListNode *nodeRes = reverseList25(&node1);
    
}
