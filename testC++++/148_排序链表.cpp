//
//  148_排序链表.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/18.
//

#include "148_排序链表.hpp"
#include "common.h"
//
//给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
//
//进阶：
//
//你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
//
//
//示例 1：
//
//
//输入：head = [4,2,1,3]
//输出：[1,2,3,4]
//示例 2：
//
//
//输入：head = [-1,5,3,4,0]
//输出：[-1,0,3,4,5]
//示例 3：
//
//输入：head = []
//输出：[]
//
//
//提示：
//
//链表中节点的数目在范围 [0, 5 * 104] 内
//-105 <= Node.val <= 105
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/sort-list
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

ListNode* _148_mergeTwoList(ListNode* head,ListNode* tail)
{
    if (!head)return tail;
    if (!tail)return head;
    if (head->val <= tail->val) {
        head->next = _148_mergeTwoList(head->next, tail);
        return head;
    }else{
        tail->next = _148_mergeTwoList(head, tail->next);
        return tail;
    }
}

ListNode* sortList(ListNode* head)
{
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    
    ListNode *next = head->next;
    if (next->next == nullptr) {    //只有2个
        if (head->val <= next->val) {
            return head;
        }else{
            next->next =head;
            head->next = nullptr;
            return next;
        }
    }
    
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast) {
        slow = slow->next;
        fast = fast->next;
        if (fast) {
            fast = fast->next;
            if (!fast || !fast->next) {
                break;
            }
        }else{
            break;
        }
    }
    //中间节点slow
    ListNode *right = sortList(slow->next);
    slow->next = nullptr;
    ListNode *left = sortList(head);
    
    return _148_mergeTwoList(left,right);
}

void _148_test()
{
    ListNode node1(4);
    ListNode node2(2);
    ListNode node3(1);
    ListNode node4(8);
    
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    
    ListNode*res = sortList(&node1);
    
}
