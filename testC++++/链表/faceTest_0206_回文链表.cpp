//
//  faceTest_0206_回文链表.cpp
//  testC++++
//
//  Created by ykh on 2020/9/14.
//

#import "faceTest_0206_回文链表.hpp"
#import "common.h"


//
//编写一个函数，检查输入的链表是否是回文的。
//
//
//
//示例 1：
//
//输入： 1->2
//输出： false
//示例 2：
//
//输入： 1->2->2->1
//输出： true
//
//
//进阶：
//你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
//
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/palindrome-linked-list-lcci
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

ListNode *reserverlist(ListNode *head){
    
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode *result = head;
    ListNode *resver = nullptr;
    ListNode *cur = head;

    while (cur !=nullptr) {
        ListNode *next = cur->next;
        cur->next = resver;
        resver = cur;
        cur = next;
    }
    return resver;
}

//区分奇数,偶数
//1.利用快慢指针找到中心节点
//2.从中心节点往后,翻转后半段
//3.对比最开始和翻转后的后半段,是否一致

//翻转链表
//   1,2,3,4,3,2,1-->     1,2,3    4  1,2,3
//   1,2,3,4,4,3,2,1-->   1,2,3,4     1,2,3,4
bool isPalindrome2(ListNode* head) {

    bool res = false;
 
    if (head == nullptr || head->next == nullptr) {
        return true;
    }
    
    int size = 0;
    ListNode *cur = head;
    while (cur!=nullptr) {
        cur=cur->next;
        size++;
    }
    cur = head;
    
    if (size%2==0) {    //偶数,慢的每次走一步,快的每次走1+1步, 并且fast还要多走一步 ,两个中心之间的距离
        ListNode *slow = head;
        ListNode *fast = head->next;
        ListNode *pre = nullptr;
        while (fast->next!=nullptr) {
            
            slow = slow->next;
            fast = fast->next->next;
        }
        pre = slow;
        slow = slow->next;
        ListNode *reserve = reserverlist(slow);
        pre->next = reserve;
        slow = reserve;
        while (slow != nullptr) {
            if (head->val != slow->val ) {
                return false;
            }
            head=head->next;
            slow = slow->next;
        }
    }else{              //奇数,慢的每次走一步,快的每次走1+1步,快的next=null,则slow在中间
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *pre = nullptr;
        while (fast->next!=nullptr) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre = slow;
        slow = slow->next;
        ListNode *reserve = reserverlist(slow);
        pre->next = reserve;
        slow = reserve;
        while (slow != nullptr) {
            if (head->val != slow->val ) {
                return false;
            }
            head=head->next;
            slow = slow->next;
        }
    }
    
    
    return true;
}


void _facetest_0206_test(){
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node41(4);
    ListNode node42(4);
    ListNode node4(3);
    ListNode node5(2);
    ListNode node6(1);
    
    ListNode node7(1);
    ListNode node8(2);
    ListNode node81(3);
    ListNode node82(2);
    ListNode node9(1);
    
    
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node41;
    node41.next = &node42;
    node42.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
    
    node7.next = &node8;
    node8.next = &node81;
    node81.next = &node82;
    node82.next = &node9;
    
//    bool res1 = isPalindrome(&node1);
    bool res2 = isPalindrome2(&node1);
    bool res3 = isPalindrome2(&node7);
    
}
