//
//  faceTest_0201_移除重复节点.cpp
//  testC++++
//
//  Created by ykh on 2020/9/11.
//

#include "faceTest_0201_移除重复节点.hpp"
#include "common.h"
//
//编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。
//
//示例1:
//
// 输入：[1, 2, 3, 3, 2, 1]
// 输出：[1, 2, 3]
//示例2:
//
// 输入：[1, 1, 1, 1, 2]
// 输出：[1, 2]
//提示：
//
//链表长度在[0, 20000]范围内。
//链表元素在[0, 20000]范围内。
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/remove-duplicate-node-lcci
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//哈希表做法

ListNode* removeDuplicateNodes0202(ListNode* head) {
    
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode* newhead;
    
    return newhead;
}


//自己做的递归
ListNode* removeDuplicateNodes0201(ListNode* head) {
    
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    
    ListNode* newhead = removeDuplicateNodes0201(head->next);
    
    int headval = head->val;
    int newheadval = newhead->val;
    if (newheadval == headval) {
        newhead = newhead->next;
        head->next = newhead;
        return head;
    }
    
    ListNode* newpre = newhead;
    ListNode* newnext = newhead->next;
    
    while (newnext!=nullptr) {
        if (headval == newnext->val) {
            newpre->next=newnext->next;
            head->next = newhead;
            return head;
            break;
        }
        newnext = newnext->next;
        newpre = newpre->next;
    }
    
    head->next = newhead;
    return head;
}

void _facetest_0201_test(){
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(3);
    ListNode node6(5);
    ListNode node7(5);
    
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
    node6.next = &node7;
    
    ListNode* head = removeDuplicateNodes0202(&node1);
    

}
