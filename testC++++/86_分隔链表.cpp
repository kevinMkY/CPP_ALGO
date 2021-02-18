//
//  86_分隔链表.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/17.
//

#include "86_分隔链表.hpp"
#include "common.h"

//给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
//
//你应当 保留 两个分区中每个节点的初始相对位置。
//
//
//
//示例 1：
//
//
//输入：head = [1,4,3,2,5,2], x = 3
//输出：[1,2,2,4,3,5]
//示例 2：
//
//输入：head = [2,1], x = 2
//输出：[1,2]
//
//
//提示：
//
//链表中节点的数目在范围 [0, 200] 内
//-100 <= Node.val <= 100
//-200 <= x <= 200
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/partition-list
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

ListNode* partition(ListNode* head, int x) {
    if (head == nullptr)return head;
    ListNode* headLow = new ListNode(0);
    ListNode* headhigh = new ListNode(0);
    ListNode* curLow = headLow;
    ListNode* curHigh = headhigh;
    while (head) {
        if (head->val < x) {
            curLow->next = head;
            curLow = curLow->next;
        }else{
            curHigh->next = head;
            curHigh = curHigh->next;
        }
        head = head->next;
    }
    curHigh->next = nullptr;
    curLow->next = headhigh->next;
    return headLow->next;
    }

void _86_test()
{
    ListNode node1(1);
    ListNode node2(4);
    ListNode node3(3);
    ListNode node4(2);
    ListNode node5(5);
    ListNode node6(2);
    
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
    
    ListNode* res = partition(&node1,3);
    
}
