//
//  offer_06_ 从尾到头打印链表.cpp
//  testC++++
//
//  Created by ykh on 2020/9/11.
//

#include "offer_06_从尾到头打印链表.hpp"
#include "common.h"


//输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
//
//
//
//示例 1：
//
//输入：head = [1,3,2]
//输出：[2,3,1]
//https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/


//第一种,顺序遍历,将每一次的新数据压栈到第一个位置,但是算法不好
vector<int> reversePrint(ListNode* head) {
    vector<int> list = {};
    //添加元素
//    list.push_back(1);
    
    if (head == nullptr) {
        return {};
    }
    
    while (head!=nullptr) {
        list.insert(list.begin(), head->val);
        head = head->next;
    }
    
    return list;
    }

//第二种,翻转列表--->遍历修改指针,利用temp保存下一个
vector<int> reversePrint2(ListNode* head) {
    vector<int> list = {};
    if (head == nullptr) {
        return {};
    }
    
    ListNode *reverse = nullptr;
    
    // 1,2,3
    while (head != nullptr) {
        ListNode *temp = head->next;
        head->next = reverse;
        reverse = head;
        head = temp;
    }
    
    while (reverse != nullptr) {
        list.push_back(reverse->val);
        reverse = reverse->next;
    }
    
    return list;
}

//第二种,翻转列表--递归

ListNode* reverseNode3(ListNode* head) {
    
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    
    ListNode *reverse = reverseNode3(head->next);
    head->next->next = head;
    head->next = nullptr;
    
    return reverse;
}

vector<int> reversePrint3(ListNode* head) {
    vector<int> list = {};
    if (head == nullptr) {
        return {};
    }
    
    ListNode *reverse = reverseNode3(head);
    
    while (reverse!=nullptr) {
        list.push_back(reverse->val);
        reverse = reverse->next;
    }
    
    return list;
}

void _offer_06_test(){
    
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    
    node1.next = &node2;
    node2.next = &node3;
    
    vector<int> list = reversePrint3(&node1);
    
}
