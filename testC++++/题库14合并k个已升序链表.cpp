//
//  题库14合并k个已升序链表.cpp
//  testC++++
//
//  Created by yekaihua on 2021/3/7.
//

#include "题库14合并k个已升序链表.hpp"
#include "common.h"

ListNode *_tk_14_test_merge2Lists(ListNode *l1,ListNode *l2){
    
    if(!l1)return l2;
    if(!l2)return l1;
    if(l1->val <= l2->val){
        l1->next = _tk_14_test_merge2Lists(l1->next,l2);
        return l1;
    }else{
        l2->next = _tk_14_test_merge2Lists(l1,l2->next);
        return l2;
    }
    return nullptr;
}

ListNode *_tk_14_test_mergeKLists(vector<ListNode *> &lists,int l ,int r) {
    if (l>r) return nullptr;
    
    int mid = l;
    while (l<r) {
        mid = l+((r-l)>>1);
        if (l==r) {
            return lists[l];
        }else if (l==r-1) {
            ListNode *left = lists[l];
            ListNode *right = lists[r];
            return _tk_14_test_merge2Lists(left,right);
        }else{
            ListNode *left = _tk_14_test_mergeKLists(lists,l,mid);
            ListNode *right = _tk_14_test_mergeKLists(lists,mid+1,r);
            return _tk_14_test_merge2Lists(left,right);
        }
    }
    
    return lists[l];
}

ListNode *_tk_14_test_mergeKLists(vector<ListNode *> &lists) {
    
    int n = lists.size();
    return _tk_14_test_mergeKLists(lists,0,n-1);
}

void _tk_14_test()
{
    vector<ListNode *>list = {};
    ListNode *res= _tk_14_test_mergeKLists(list);
    //小顶堆,升序队列

    
}
