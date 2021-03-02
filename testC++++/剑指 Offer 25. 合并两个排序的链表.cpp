//
//  剑指 Offer 25.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/26.
//

#include "剑指 Offer 25. 合并两个排序的链表.hpp"
#include "common.h"

ListNode* _offer_25_repeat_testmergeTwoLists(ListNode* l1, ListNode* l2) {

    if (!l1) {return l2;}
    if (!l2) {return l1;}
    
    
    if (l1->val > l2->val) {
        l2->next = _offer_25_repeat_testmergeTwoLists(l1,l2->next);
        return l2;
    }else{
        l1->next = _offer_25_repeat_testmergeTwoLists(l1->next,l2);
        return l1;
    }
    
    
    }

ListNode* _offer_25_repeat_testmergeTwoLists2(ListNode* l1, ListNode* l2) {

    if (!l1) {return l2;}
    if (!l2) {return l1;}
    
    ListNode *dummy = new ListNode(0);
    ListNode *cur = dummy;
    
    while (l1 || l2) {
        if (l1 && l2) {
            if (l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            }else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }else if (l1){
            cur->next = l1;
            break;
        }else if (l2){
            cur->next = l2;
            break;
        }
    }
    
    return dummy->next;
    }


ListNode* _offer_25_repeat_testmergeTwoLists3(ListNode* l1, ListNode* l2) {
    
    if (!l1) {
        return l2;
    }
    if (!l2) {
        return l1;
    }
    
    if (l1->val <= l2->val) {
        l1->next = _offer_25_repeat_testmergeTwoLists3(l1->next,l2);
        return l1;
    }else{
        l2->next = _offer_25_repeat_testmergeTwoLists3(l1,l2->next);
        return l2;
    }
}

void _offer_25_repeat_test()
{
    
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(4);
    
    ListNode node4(1);
    ListNode node5(3);
    ListNode node6(4);
    
    
    node1.next = &node2;
    node2.next = &node3;
//    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
//    node6.next = &node7;
    
    ListNode *res = _offer_25_repeat_testmergeTwoLists3(&node1,&node4);
    
}
