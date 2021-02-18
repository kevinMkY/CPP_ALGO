//
//  234_回文链表.cpp
//  testC++++
//
//  Created by ykh on 2020/9/14.
//

#import "234_回文链表.hpp"
#import "common.h"

//请判断一个链表是否为回文链表。
//
//示例 1:
//
//输入: 1->2
//输出: false
//示例 2:
//
//输入: 1->2->2->1
//输出: true
//进阶：
//你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/palindrome-linked-list
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

ListNode* reserlist(ListNode* head){
    if (head == nullptr || head->next==nullptr) {
        return head;
    }
    
    ListNode *pre = nullptr;
    ListNode *cur = head;
    while (cur!=nullptr) {
        ListNode *temp = cur->next;
        cur->next=pre;
        pre=cur;
        cur=temp;
    }
    return pre;
}

bool isPalindrome(ListNode* head) {

    if (head == nullptr || head->next == nullptr) {
        return true;
    }
    
    ListNode* cur = head;
    
    int size = 0;
    while (cur!=nullptr) {
        cur=cur->next;
        size++;
    }
    
    //   1,2,3,4,3,2,1-->     1,2,3    4  1,2,3
    //   1,2,3,4,4,3,2,1-->   1,2,3,4     1,2,3,4
    ListNode* slow = head;
    ListNode* fast = head;
    if (size%2==0) {
        fast = head->next;
    }
    while (fast->next!=nullptr) {
        
        slow =slow->next;
        fast =fast->next->next;
    }
    slow = slow->next;
    ListNode* reserresult = reserlist(slow);
    slow = reserresult;
    while (slow!=nullptr) {
        if (head->val != slow->val) {
            return false;
        }
        head=head->next;
        slow=slow->next;
    }
    
    
    return true;
    }

ListNode* reserlist3(ListNode *head){
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode *next = reserlist3(head->next);
    ListNode *cur = next;
    ListNode *pre = nullptr;
    while (cur) {
        pre = cur;
        cur = cur->next;
    }
    pre->next = head;
    head->next = nullptr;
    return next;
}

bool isPalindrome3(ListNode* head){
    if (head == nullptr || head->next == nullptr) {
        return true;
    }
    
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *middle = nullptr;
    //找middle
    while (fast) {
        if (fast->next && fast->next->next) {
            fast = fast->next->next;
        }else{
            middle = slow;
            break;
        }
        slow = slow->next;
    }
    //将middle之后的翻转
    ListNode *reslist = reserlist3(middle->next);
    while (reslist) {
        if (reslist->val == head->val) {
            reslist = reslist->next;
            head = head->next;
        }else{
            return false;
        }
    }
    
    return true;
}

void _234_test_(){
    ListNode node1(1);
    ListNode node2(3);
    ListNode node3(2);
    
    ListNode node4(4);
    
    ListNode node5(3);
    ListNode node6(2);
    ListNode node7(1);
//    ListNode node8(1);
    
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
    node6.next = &node7;
//    node7.next = &node8;
//    node8.next = &node81;
//    node81.next = &node82;
//    node82.next = &node9;
    bool res3 = isPalindrome3(&node1);
    
}
