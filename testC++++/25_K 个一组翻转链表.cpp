//
//  25_K 个一组翻转链表.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/18.
//

#include "25_K 个一组翻转链表.hpp"
#include "common.h"

//给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
//
//k 是一个正整数，它的值小于或等于链表的长度。
//
//如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
//
//
//
//示例：
//
//给你这个链表：1->2->3->4->5
//
//当 k = 2 时，应当返回: 2->1->4->3->5
//
//当 k = 3 时，应当返回: 3->2->1->4->5
//
//
//
//说明：
//
//你的算法只能使用常数的额外空间。
//你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/reverse-nodes-in-k-group
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

pair<ListNode*, ListNode*> reverseKPair(ListNode* head,ListNode* tail) {
    ListNode *pre = head;
    ListNode *next = tail->next;
    while (next!=tail) {
        ListNode *tmp = pre->next;
        pre->next = next;
        next = pre;
        pre = tmp;
    }
    return {tail,head};
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *tail = dummy;
    ListNode *pre = dummy;
    ListNode *next = nullptr;
    
    while (head) {
        //查看剩余长度是否满足,不满足则不翻转
        for (int i = 0; i<k; i++) {
            tail = tail->next;
            if (!tail) {
                return dummy->next;
            }
        }
        //tail 已经走到尾巴
        next = tail->next;
        //将head和tail传递进去作为翻转的头尾
//        pair<ListNode *, ListNode *>pn = reverseKPair(head,tail);
//        head = pn.first;
//        tail = pn.second;
        tie(head,tail) = reverseKPair(head,tail);
        pre->next = head;
        tail->next = next;
        //重置
        pre = tail;
        head = next;
    }
    
    return dummy->next;
    }

void _25_test()
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
    int flag1 = 2;
    
    ListNode*res = reverseKGroup(&node1,flag1);
    
    
}
