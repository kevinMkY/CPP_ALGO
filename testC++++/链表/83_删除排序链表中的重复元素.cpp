//
//  83_删除排序链表中的重复元素.cpp
//  testC++++
//
//  Created by ykh on 2020/9/9.
//

#import "83_删除排序链表中的重复元素.hpp"
#import "common.h"

//给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
//
//示例 1:
//
//输入: 1->1->2
//输出: 1->2
//示例 2:
//
//输入: 1->1->2->3->3
//输出: 1->2->3
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//该列表为有序列表
ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode *pre = head;
    ListNode *cur = head->next;
    while (cur != nullptr) {
        if (pre->val == cur->val) {
            pre->next = cur->next;
        }else{
            pre = cur;
        }
        cur = cur->next;
    }
    return head;
}

void _83_test(){

    ListNode node1(1);
    ListNode node2(1);
    ListNode node3(2);
    ListNode node4(2);
    ListNode node5(3);
    ListNode node6(3);
    ListNode node7(4);
    
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
    node6.next = &node7;
    
    ListNode *nodeRes = deleteDuplicates(&node1);
    
}
