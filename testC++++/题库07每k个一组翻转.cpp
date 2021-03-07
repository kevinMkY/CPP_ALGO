//
//  题库07每k个一组翻转.cpp
//  testC++++
//
//  Created by yekaihua on 2021/3/6.
//

#include "题库07每k个一组翻转.hpp"
#include "common.h"

pair< ListNode*,ListNode*> _tk_07_test_reverseKGroup(ListNode* head,ListNode* tail) {
    ListNode *newhead = nullptr;
    ListNode *oldHead = head;
    while(head != tail){
        ListNode *next = head->next;
        head->next = newhead;
        newhead = head;
        head = next;
    }
    tail->next = newhead;
    
    return {tail,oldHead};
    }
    ListNode* _tk_07_test_reverseKGroup(ListNode* head, int k) {
        // write code here
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *cur = head;
        ListNode *pre = dummy;
        while(cur){
            //1
            ListNode *head = cur;
            //1
            ListNode *tail = cur;
            for (int i = 0; i<k-1; i++) {
                tail=tail->next;
                if (!tail) {
                    return dummy->next;
                }
            }
            //head 1
            //tail 3
            //next 4
            ListNode *next = tail->next;
            auto it = _tk_07_test_reverseKGroup(head,tail);
            head = it.first;
            tail = it.second;
            pre->next = head;
            tail->next = next;
            pre=tail;
            cur = next;
        }
        return dummy->next;
    }

pair<ListNode*, ListNode*>_tk_07_test_reverse2(ListNode* head, ListNode* tail){
    
    ListNode *oldHead = head;
    ListNode *newhead = nullptr;
    while (head != tail) {
        ListNode *next = head->next;
        head->next = newhead;
        newhead = head;
        head = next;
    }
    if (tail) {
        tail->next = newhead;
    }
    return {tail,oldHead};
}

ListNode* _tk_07_test_reverseKGroup2(ListNode* head, int k) {
    if (!head || !head->next) {
        return head;
    }    // write code here
    
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode*pre = dummy;
    ListNode*tail = head;
    ListNode*next = nullptr;
    while (head) {
        for (int i = 1; i<k; i++) {
            tail = tail->next;
            if (!tail) {
                return dummy->next;
            }
        }
        next = tail->next;
        //head,tail已就绪
        auto it = _tk_07_test_reverse2(head,tail);
        head = it.first;
        tail = it.second;
        pre->next = head;
        tail->next = next;
        pre = tail;
        head = next;
        tail = head;
    }
    
    return dummy->next;
}


void _tk_07_test()
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
    ListNode*res= _tk_07_test_reverseKGroup2(&node1,flag1);
    
}
