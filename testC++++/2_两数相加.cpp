//
//  2_两数相加.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/17.
//

#include "2_两数相加.hpp"
#include "common.h"

//给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
//
//请你将两个数相加，并以相同形式返回一个表示和的链表。
//
//你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
//
//
//
//示例 1：
//
//
//输入：l1 = [2,4,3], l2 = [5,6,4]
//输出：[7,0,8]
//解释：342 + 465 = 807.
//示例 2：
//
//输入：l1 = [0], l2 = [0]
//输出：[0]
//示例 3：
//
//输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
//输出：[8,9,9,9,0,0,0,1]
//
//
//提示：
//
//每个链表中的节点数在范围 [1, 100] 内
//0 <= Node.val <= 9
//题目数据保证列表表示的数字不含前导零
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/add-two-numbers
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//2->4->3
//5->6->4
//7->0->8
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr ) return l2;
    if (l2 == nullptr ) return l1;
    ListNode* res = new ListNode(0);
    ListNode *tail = res;
    while (l1 || l2) {
        int val = 0;
        if (l1) {
            val+=l1->val;
            l1 = l1->next;
        }
        if (l2) {
            val+=l2->val;
            l2 = l2->next;
        }
        if (tail->next && tail->next->val) {
            val+=tail->next->val;
        }
        ListNode *node = new ListNode(val%10);
        if (val>=10) {
            node->next = new ListNode(val/10);
        }
        tail->next = node;
        tail = tail->next;
    }
    return res->next;
    }

ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
    
    if (!l1) return l2;
    if (!l2) return l1;
    
    ListNode *newhead = new  ListNode(0);
    ListNode *newTail = newhead;
    int carry = 0;
    while (l1 || l2) {
        int v1=0,v2= 0;
        if (l1 ) {
            v1 = l1->val;
            l1 = l1->next;
        }
        if (l2 ) {
            v2 = l2->val;
            l2 = l2->next;
        }
        int sum = v1 + v2 + carry;
        carry = sum/10;
        newTail->next = new ListNode(sum%10);
        newTail = newTail->next;
    }
    if (carry > 0) {
        newTail->next = new ListNode(carry);
    }
    return newhead->next;
}


ListNode* addTwoNumbers3(ListNode* l1, ListNode* l2) {
    
    if (!l1) return l2;
    if (!l2) return l1;
    
    ListNode *res = new ListNode(0);
    ListNode *tail = res;
    bool needIncrease = false;
    while (l1 || l2) {
        int val = 0;
        if (l1) {
            val += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            val += l2->val;
            l2 = l2->next;
        }
        val = (val + (needIncrease ? 1 : 0));
        tail->next = new ListNode(val%10);
        tail = tail->next;
        needIncrease = val/10;
    }
    if (needIncrease) {
        tail->next = new ListNode(1);
    }
    return res->next;;
}

void _2_test()
{
    ListNode node1(2);
    ListNode node2(4);
    ListNode node3(3);
    
    
    ListNode node5(5);
    ListNode node6(6);
    ListNode node7(4);
    
    node1.next = &node2;
    node2.next = &node3;
    
    node5.next = &node6;
    node6.next = &node7;
    
    ListNode *res = addTwoNumbers3(&node1,&node5);
    
    
}
