//
//  21_合并两个有序链表.cpp
//  testC++++
//
//  Created by ykh on 2020/9/14.
//

#import "21_合并两个有序链表.hpp"
#import "common.h"

//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
//
//
//
//示例：
//
//输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/merge-two-sorted-lists
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



//
//
//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
//
//
//
//示例：
//
//输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/merge-two-sorted-lists
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//递归解法
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr ) {
        return l2;
    }else if (l2 == nullptr ) {
        return l1;
    }
    
    int val1 = l1->val;
    int val2 = l2->val;
    
    if (val1 > val2) {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }else{
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
}

//迭代解法---生成一个新链表,将每一个小值插入新链表中
ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr ) {
        return l2;
    }else if (l2 == nullptr ) {
        return l1;
    }
    
    ListNode node(-1);
    ListNode* res = &node;
    ListNode* prev = res;
    
    while (l1 != nullptr && l2 != nullptr) {
        int val1 = l1->val;
        int val2 = l2->val;
        
        if (val1 > val2) {
            prev->next = l2;
            prev = l2;
            l2 = l2->next;
        }else{
            prev->next = l1;
            prev = l1;
            l1 = l1->next;
        }
    }
    
    if (l1 != nullptr) {
        prev->next = l1;
    }
    if (l2 != nullptr) {
        prev->next = l2;
    }
    
    return res->next;
}

void _21_test(){
    ListNode node1(1);
    ListNode node2(2);
    ListNode node4(4);
    
    
    ListNode node5(1);
    ListNode node6(3);
    ListNode node7(4);
    
    node1.next = &node2;
    node2.next = &node4;
    
    node5.next = &node6;
    node6.next = &node7;
    
    ListNode *nodeRes = mergeTwoLists2(&node1,&node5);
    
}
