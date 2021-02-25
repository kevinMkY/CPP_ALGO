//
//  剑指 Offer 06.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/25.
//

#include "剑指 Offer 06. 从尾到头打印链表.hpp"
#include "common.h"

//输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
//
//
//
//示例 1：
//
//输入：head = [1,3,2]
//输出：[2,3,1]
//
//
//限制：
//
//0 <= 链表长度 <= 10000
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


vector<int> _offer_06_repeat_testreversePrint(ListNode* head) {
    
    if (!head) {
        return {};
    }
    vector<int> res;
    if (head->next) {
        res = _offer_06_repeat_testreversePrint(head->next);
    }
    res.push_back(head->val);
    
    return res;
    }

vector<int> _offer_06_repeat_testreversePrint2(ListNode* head) {
    
    if (!head) {
        return {};
    }
    
    stack<int>mystack;
    vector<int>res;
    
    while (head) {
        mystack.push(head->val);
        head = head->next;
    }
    while (mystack.size()) {
        res.push_back(mystack.top());
        mystack.pop();
    }
    
    return res;
    }

vector<int> _offer_06_repeat_testreversePrint3(ListNode* head) {
    
    if (!head) {
        return {};
    }
    vector<int>res;
    
    while (head) {
        res.push_back(head->val);
        head = head->next;
    }
    reverse(res.begin(),res.end());
    return res;
}


void _offer_06_repeat_test()
{
    ListNode node1(1);
    ListNode node2(3);
    ListNode node3(2);
    
    
    
    node1.next = &node2;
    node2.next = &node3;
    vector<int> res = _offer_06_repeat_testreversePrint2(&node1);
    
    
}
