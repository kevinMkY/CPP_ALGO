//
//  3_环形链表.cpp
//  testC++++
//
//  Created by ykh on 2020/9/9.
//

#include "141_环形链表.hpp"
#include "common.h"

//给定一个链表，判断链表中是否有环。
//
//为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
//
//
//
//示例 1：
//
//输入：head = [3,2,0,-4], pos = 1
//输出：true
//解释：链表中有一个环，其尾部连接到第二个节点。
//
//
//示例 2：
//
//输入：head = [1,2], pos = 0
//输出：true
//解释：链表中有一个环，其尾部连接到第一个节点。
//
//
//示例 3：
//
//输入：head = [1], pos = -1
//输出：false
//解释：链表中没有环。
//
//
//
//
//进阶：
//
//你能用 O(1)（即，常量）内存解决此问题吗？
//
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/linked-list-cycle
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



//判断有环,用快慢指针
bool hasCycle(ListNode *head) {
    
    if (head == nullptr || head->next == nullptr) {
        return false;
    }
    
    ListNode *slow = head;
    ListNode *fast = head->next;
    ListNode *middle = nullptr;
    
    while (fast != nullptr) {
        if (slow == fast) {
            return true;
        }
        slow = slow->next;
        middle = fast->next;
        if (middle == nullptr) {
            break;
        }
        fast = fast->next->next;
    }
    
    return false;
}

void _141_test()
{
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node2;
    
    bool res = hasCycle(&node1);
    
}
