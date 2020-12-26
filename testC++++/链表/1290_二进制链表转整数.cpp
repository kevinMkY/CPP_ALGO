//
//  1290_二进制链表转整数.cpp
//  testC++++
//
//  Created by ykh on 2020/9/11.
//

#import "1290_二进制链表转整数.hpp"
#import "common.h"

//给你一个单链表的引用结点 head。链表中每个结点的值不是 0 就是 1。已知此链表是一个整数数字的二进制表示形式。
//
//请你返回该链表所表示数字的 十进制值 。
//
// 
//
//示例 1：
//
//
//
//输入：head = [1,0,1]
//输出：5
//解释：二进制数 (101) 转化为十进制数 (5)
//示例 2：
//
//输入：head = [0]
//输出：0
//示例 3：
//
//输入：head = [1]
//输出：1
//示例 4：
//
//输入：head = [1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]
//输出：18880
//示例 5：
//
//输入：head = [0,0]
//输出：0
// 
//
//提示：
//
//链表不为空。
//链表的结点总数不超过 30。
//每个结点的值不是 0 就是 1。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/convert-binary-number-in-a-linked-list-to-integer
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

int getNumFor2(int num){
    if (num == 0) {
        return 1;
    }
    
    int sum = 1;
    for (int i = 0; i<num; i++) {
        sum = sum * 2;
    }
    return sum;
}

int getDecimalValue(ListNode* head) {

    if (head == nullptr) {
        return 0;
    }
    
    int size = 1;
    ListNode *next = head->next;
    while (next != nullptr) {
        next = next->next;
        size++;
    }
    
    int sum = 0;
    int index = size - 1;
    
    next = head;
    while (next != nullptr && index >= 0) {
        int num = 0;
        if (next->val > 0) {
            num = getNumFor2(index);
        }
        sum += num;
        index--;
        next = next->next;
    }
    
    return sum;
    }

void _1290_test(){
    
    ListNode node1(1);
    ListNode node2(0);
    ListNode node3(0);
    ListNode node4(1);
    ListNode node5(0);
    ListNode node6(0);
    ListNode node7(1);
    ListNode node8(1);
    ListNode node9(1);
    ListNode node10(0);
    ListNode node11(0);
    ListNode node12(0);
    ListNode node13(0);
    ListNode node14(0);
    ListNode node15(0);
    
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
    node6.next = &node7;
    node7.next = &node8;
    node8.next = &node9;
    node9.next = &node10;
    node10.next = &node11;
    node11.next = &node12;
    node12.next = &node13;
    node13.next = &node14;
    node14.next = &node15;
    
    int res = getDecimalValue(&node1);
    
}
