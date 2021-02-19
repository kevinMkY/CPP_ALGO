//
//  328_奇偶链表.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/19.
//

#include "328_奇偶链表.hpp"
#include "common.h"

//给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。
//
//请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。
//
//示例 1:
//
//输入: 1->2->3->4->5->NULL
//输出: 1->3->5->2->4->NULL
//示例 2:
//
//输入: 2->1->3->5->6->4->7->NULL
//输出: 2->3->6->7->1->5->4->NULL
//说明:
//
//应当保持奇数节点和偶数节点的相对顺序。
//链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/odd-even-linked-list
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
        return head;
    }
    
    ListNode *dummy = new ListNode(0);
    ListNode *dummy2 = new ListNode(0);
    
    ListNode *oddNumber = dummy;
    ListNode *evenNumber = dummy2;
    
    ListNode *cur = head;
    int count = 1;
    while (cur) {
        if (count%2==1) {
            oddNumber->next = cur;
            oddNumber = cur;
        }else{
            evenNumber->next = cur;
            evenNumber = cur;
        }
        count++;
        cur=cur->next;
    }
    oddNumber->next = dummy2->next;
    evenNumber->next = nullptr;
    return dummy->next;
}

void _328_test()
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
    ListNode*res = oddEvenList(&node1);
    
}
