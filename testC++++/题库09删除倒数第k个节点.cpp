//
//  题库09删除倒数第k个节点.cpp
//  testC++++
//
//  Created by yekaihua on 2021/3/6.
//

#include "题库09删除倒数第k个节点.hpp"
#include "common.h"

ListNode* _tk_09_test_removeNthFromEnd(ListNode* head, int n) {
        // write code here
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *fast = dummy;
        ListNode *slow = dummy;
        ListNode *pre = dummy;
        while(fast){
            for(;n>0;n--){
                fast = fast->next;
                if(!fast)return nullptr;
            }
            pre = slow;
            slow = slow->next;
            fast = fast->next;
        }
        if(pre && slow){
            pre->next = slow->next;
        }
        return dummy->next;
    }

void _tk_09_test()
{
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(0);
    ListNode node4(-4);
//    ListNode node5(5);
    
    node1.next = &node2;
//    node2.next = &node3;
//    node3.next = &node4;
//    node4.next = &node2;
    
    ListNode *res= _tk_09_test_removeNthFromEnd(&node1,2);
    
}
