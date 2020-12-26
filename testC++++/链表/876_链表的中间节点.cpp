//
//  876_链表的中间节点.cpp
//  testC++++
//
//  Created by ykh on 2020/9/9.
//

#import "876_链表的中间节点.hpp"
#import "common.h"

//给定一个带有头结点 head 的非空单链表，返回链表的中间结点。
//
//如果有两个中间结点，则返回第二个中间结点。
//
// 
//
//示例 1：
//
//输入：[1,2,3,4,5]
//输出：此列表中的结点 3 (序列化形式：[3,4,5])
//返回的结点值为 3 。 (测评系统对该结点序列化表述是 [3,4,5])。
//注意，我们返回了一个 ListNode 类型的对象 ans，这样：
//ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, 以及 ans.next.next.next = NULL.
//示例 2：
//
//输入：[1,2,3,4,5,6]
//输出：此列表中的结点 4 (序列化形式：[4,5,6])
//由于该列表有两个中间结点，值分别为 3 和 4，我们返回第二个结点。
// 
//
//提示：
//
//给定链表的结点数介于 1 和 100 之间。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/middle-of-the-linked-list
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//两边循环
ListNode* middleNode(ListNode* head) {
    
    int num = 0;
    int secondNum = 0;
    ListNode *cur = head;
    while (cur != nullptr) {
        cur = cur->next;
        num++;
    }
    
    cur = head;
    while (cur != nullptr) {
        cur = cur->next;
        secondNum++;
        if (secondNum == num/2) {
            return cur;
        }
    }
    
    return head;
}

//快慢指针
ListNode* middleNode2(ListNode* head) {
    
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    
    ListNode *slow = head;
    ListNode *fast = head->next;
    ListNode *middle;
    
    while (fast != nullptr) {
        slow = slow->next;
        middle = fast->next;
        if (middle == nullptr) {
            return slow;
        }
        fast = fast->next->next;
    }
    
    return slow;
}

void _876_test(){
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);
    ListNode node6(6);
    ListNode node7(7);
    ListNode node8(8);
    
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
    node6.next = &node7;
//    node7.next = &node8;
    
    ListNode *nodeRes = middleNode2(&node1);
    
}
