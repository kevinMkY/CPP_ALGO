//
//  offer_18_删除链表的节点.cpp
//  testC++++
//
//  Created by ykh on 2020/9/14.
//

#include "offer_18_删除链表的节点.hpp"
#include "common.h"

//
//给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
//
//返回删除后的链表的头节点。
//
//注意：此题对比原题有改动
//
//示例 1:
//
//输入: head = [4,5,1,9], val = 5
//输出: [4,1,9]
//解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
//示例 2:
//
//输入: head = [4,5,1,9], val = 1
//输出: [4,5,9]
//解释: 给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.
//
//
//说明：
//
//题目保证链表中节点的值互不相同
//若使用 C 或 C++ 语言，你不需要 free 或 delete 被删除的节点
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//添加一个哨兵头,双指针
ListNode* deleteNode(ListNode* head, int val) {

    if (head == nullptr) {
        return nullptr;
    }
    
    ListNode node(-1);
    
    ListNode *res = &node;
    res->next = head;
    
    ListNode *cur = res->next;
    ListNode *pre = res;
    while (cur != nullptr) {
        if (cur->val == val) {
            pre->next = cur->next;
        }else{
            pre = pre->next;
        }
        cur=cur->next;
    }
    
    return res->next;
    }

//递归
ListNode* deleteNode3(ListNode* head, int val) {

    if (head == nullptr) {
        return nullptr;
    }
    
    ListNode *res = deleteNode3(head->next, val);
    if (head->val == val) {
        return res;
    }else{
        head->next = res;
        return head;
    }
}

void _offer_18_test(){
    ListNode node1(1);
    ListNode node2(4);
    ListNode node3(1);
    ListNode node4(9);
    
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    
    ListNode* list = deleteNode3(&node1,1);
    
}
