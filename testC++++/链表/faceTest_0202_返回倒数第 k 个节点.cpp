//
//  faceTest_0202_返回倒数第 k 个节点.cpp
//  testC++++
//
//  Created by ykh on 2020/9/11.
//

#include "faceTest_0202_返回倒数第 k 个节点.hpp"
#include "common.h"

//实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。
//
//注意：本题相对原题稍作改动
//
//示例：
//
//输入： 1->2->3->4->5 和 k = 2
//输出： 4
//说明：
//
//给定的 k 保证是有效的。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/kth-node-from-end-of-list-lcci
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//正常手法
int kthToLast(ListNode* head, int k) {

    if (head == nullptr) {
        return 0;
    }
    
    int size = 1;
    
    ListNode *next = head->next;
    
    while (next != nullptr) {
        next = next->next;
        size++;
    }
    
    int targetIndex = size + 1 - k;
    next = head;
    
    for (int i = 1; i<targetIndex; i++) {
        next = next->next;
    }
    
    
    return next->val;
    }

//快慢指针
//设置快和慢两个指针，初始化时快指针比慢指针多走k-1步，然后两个指针每次都走一步，当快指针到达终点时，慢指针正好处在倒数第k的位置
//1,2,3,4,5     2    倒数第二个距离倒数第一个,之间的间距只有1
//              slow = 1
//              fast = 1 + (2 - 1);
int kthToLast2(ListNode* head, int k) {
    
    if (head == nullptr) {
        return 0;
    }
    
    ListNode *slow = head;
    ListNode *fast = head->next;
    
    int slowNum = 1;
    int fastNum = slowNum + (k - 1);
    
    while (fast!=nullptr) {
        fast = fast->next;
        if (slowNum < fastNum) {
            
        }else{
            slow = slow->next;
        }
        slowNum++;
    }
    
    return slow->val;
}


void _face_0202_test(){
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);
    ListNode node6(3);
    ListNode node7(4);
    
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
//    node5.next = &node6;
//    node6.next = &node7;
    
    int res = kthToLast2(&node1,2);
    
}
