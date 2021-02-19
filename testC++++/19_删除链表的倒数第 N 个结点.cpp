//
//  19_删除链表的倒数第 N 个结点.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/18.
//

#include "19_删除链表的倒数第 N 个结点.hpp"
#include "common.h"

//给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
//
//进阶：你能尝试使用一趟扫描实现吗？
//
//
//
//示例 1：
//
//
//输入：head = [1,2,3,4,5], n = 2
//输出：[1,2,3,5]
//示例 2：
//
//输入：head = [1], n = 1
//输出：[]
//示例 3：
//
//输入：head = [1,2], n = 1
//输出：[1]
//
//
//提示：
//
//链表中结点的数目为 sz
//1 <= sz <= 30
//0 <= Node.val <= 100
//1 <= n <= sz
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

ListNode* removeNthFromEnd(ListNode* head, int n) {

    if (head == nullptr) {
        return head;
    }
    
    ListNode *slow = head;
    ListNode *fast = head;
    int size = 1;
    int slowCount = 1;
    bool hasFast = true;
    //虚拟
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *pre = dummy;
    
    //
    ListNode *predelete = dummy;
    int predeleteCount = 0;
    
    //遍历
    while (slow) {
        //slow
        pre = slow;
        slow = slow->next;
        slowCount++;
        //fast
        if (fast) {
            fast = fast->next;
        }
        if (fast) {
            size++;
            fast = fast->next;
            if (fast) {
                size++;
                hasFast = fast->next ? true : false;
            }else{
                hasFast = false;
            }
        }else{
            hasFast = false;
        }
        //
        if (!hasFast) {
            if (slowCount == size-n+1) {  //说明要删除的还在slow的右边
                pre->next = slow->next;
                break;
            }else if(slowCount < size-n+1) {
                
            }else{  //slowCount > size-n+1) {
                if (predeleteCount == size-n) { //要删的前一个
                    predelete->next = predelete->next->next;
                    break;
                }else{
                    predelete = predelete->next;
                    predeleteCount++;
                }
            }
        }
    }
    
    return dummy->next;
    }

ListNode* removeNthFromEnd2(ListNode* head, int n) {
    if (head == nullptr) {return head;}
    
    int count =0;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *pre = dummy;
    
    ListNode *slow = head;
    ListNode *fast = head;
    for (int i = 0; i<n; i++) {
        fast = fast->next;
    }
    while (fast) {
        pre = slow;
        slow = slow->next;
        fast = fast->next;
    }
    
    
    pre->next = slow->next;
    
    return dummy->next;
}

void _19_test()
{
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    
    ListNode node4(4);
    ListNode node5(5);
    ListNode node6(6);
    
    
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
//    node5.next = &node6;
    
    
    ListNode *res = removeNthFromEnd2(&node1,5);
    
}
