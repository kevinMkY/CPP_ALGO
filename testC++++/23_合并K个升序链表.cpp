//
//  23_合并K个升序链表.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/18.
//

#include "23_合并K个升序链表.hpp"
#include "common.h"

//给你一个链表数组，每个链表都已经按升序排列。
//
//请你将所有链表合并到一个升序链表中，返回合并后的链表。
//
//
//
//示例 1：
//
//输入：lists = [[1,4,5],[1,3,4],[2,6]]
//输出：[1,1,2,3,4,4,5,6]
//解释：链表数组如下：
//[
//  1->4->5,
//  1->3->4,
//  2->6
//]
//将它们合并到一个有序链表中得到。
//1->1->2->3->4->4->5->6
//示例 2：
//
//输入：lists = []
//输出：[]
//示例 3：
//
//输入：lists = [[]]
//输出：[]
//
//
//提示：
//
//k == lists.length
//0 <= k <= 10^4
//0 <= lists[i].length <= 500
//-10^4 <= lists[i][j] <= 10^4
//lists[i] 按 升序 排列
//lists[i].length 的总和不超过 10^4
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/merge-k-sorted-lists
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//迭代
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.size() == 0) {
        return nullptr;
    }
    ListNode *newhead = new ListNode(INT_MIN);
    ListNode *pre = newhead;
    stack<ListNode *>mystack;
    stack<ListNode *>prestack;
    prestack.push(pre);
    
    for (int i =0 ;i<lists.size(); i++) {
        ListNode*node = lists[i];
        //和pre比
        while (node) {
            if (mystack.size()) {
                ListNode *cache = mystack.top();
                if (node->val > cache->val) {
                    cache->next = node;
                    mystack.pop();
                    node = cache;
                }
            }
            if (pre->val > node->val) {
                mystack.push(pre);
                prestack.pop();
                pre = prestack.top();
            }else{
                pre->next = node;
                pre = node;
                prestack.push(node);
                node = node->next;
            }
        }
    }
    while (mystack.size()) {
        ListNode *cache = mystack.top();
        pre->next = cache;
        pre = cache;
        mystack.pop();
        prestack.push(pre);
    }
    return newhead->next;
    }

//递归--分治

ListNode* mergeTwoList(ListNode*left,ListNode*right) {
    if (!left) return right;
    if (!right)return left;
    if (left->val <= right->val) {
        ListNode *next = mergeTwoList(left->next, right);
        left->next = next;
        return left;
    }else{
        ListNode *next = mergeTwoList(left, right->next);
        right->next = next;
        return right;
    }
}

ListNode* mergeKListsIndex2(vector<ListNode*>& lists,int leftIndex,int rightIndex) {
    if (leftIndex == rightIndex)return lists[leftIndex];
    if (leftIndex >rightIndex) return nullptr;
    int mid = (leftIndex + rightIndex)>>1;
    ListNode *left = mergeKListsIndex2(lists, leftIndex, mid);
    ListNode *right = mergeKListsIndex2(lists, mid+1, rightIndex);
    return mergeTwoList(left,right);
}

ListNode* mergeKLists2(vector<ListNode*>& lists) {
    return mergeKListsIndex2(lists,0,(int)lists.size()-1);
}

void _23_test()
{
    ListNode node1(1);
    ListNode node2(4);
    ListNode node4(5);
    
    
    ListNode node5(1);
    ListNode node6(3);
    ListNode node7(4);
    
    ListNode node9(2);
    ListNode node10(6);
    
    ListNode node11(0);
    
    node1.next = &node2;
    node2.next = &node4;

    node5.next = &node6;
    node6.next = &node7;

    node9.next = &node10;
    
    vector<ListNode*> list1 = {&node1,&node5,&node9};
    ListNode*res = mergeKLists2(list1);
    
    
}
