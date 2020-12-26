//
//  faceTest_0207_链表相交.cpp
//  testC++++
//
//  Created by ykh on 2020/9/14.
//

#import "faceTest_0207_链表相交.hpp"
#import "common.h"

//给定两个（单向）链表，判定它们是否相交并返回交点。请注意相交的定义基于节点的引用，而不是基于节点的值。换句话说，如果一个链表的第k个节点与另一个链表的第j个节点是同一节点（引用完全相同），则这两个链表相交。
//
//
//示例 1：
//
//输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
//输出：Reference of the node with value = 8
//输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
//
//示例 2：
//
//输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
//输出：Reference of the node with value = 2
//输入解释：相交节点的值为 2 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
//
//示例 3：
//
//输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
//输出：null
//输入解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
//解释：这两个链表不相交，因此返回 null。
//
//注意：
//
//如果两个链表没有交点，返回 null 。
//在返回结果后，两个链表仍须保持原有的结构。
//可假定整个链表结构中没有循环。
//程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/intersection-of-two-linked-lists-lcci
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



//----------------------------------------------------------------------------------
//                      本道题的意思
//注意 因为如果链表A和链表B相交于D的话,那么说明D结点即在A上又在B上,而D之后的元素自然也就均在A和B上了,因为他们是通过next指针相连的.

//尾部对齐,然后循环对比
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    
    if (headA == nullptr || headB == nullptr) {
        return nullptr;
    }
    
    int sizeA = 0;
    ListNode *curA = headA;
    while (curA != nullptr) {
        sizeA++;
        curA = curA->next;
    }
    int sizeB = 0;
    ListNode *curB = headB;
    while (curB != nullptr) {
        sizeB++;
        curB = curB->next;
    }
    
    int modify = sizeA - sizeB;
    
    ListNode *res;
    curA = headA;
    curB = headB;
    if (modify > 0) {
        res = curB;
        for (int i = 0; i<sizeA; i++) {
            if (i<modify) {
                curA = curA->next;
            }else{
                if (curA != curB) {
                    res = curB->next;
                }
                curA = curA->next;
                curB = curB->next;
            }
        }
    }else if (modify <= 0) {
        modify = -modify;
        res = curA;
        for (int i = 0; i<sizeB; i++) {
            if (i<modify) {
                curB = curB->next;
            }else{
                if (curA != curB) {
                    res = curA->next;
                }
                curA = curA->next;
                curB = curB->next;
            }
        }
    }
    
    return res;
}

//https://leetcode-cn.com/problems/intersection-of-two-linked-lists-lcci/solution/dai-ma-jie-shi-shuang-zhi-zhen-suan-fa-wei-shi-yao/

//两指针走一遍对方的前半截节点,最后一定会都停在相交那
ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
    ListNode *t1 = headA;
    ListNode *t2 = headB;
    
    while (t1 != t2) {
        if (t1 == nullptr) {
            t1 = headB;
        }else{
            t1 = t1->next;
        }
        if (t2 == nullptr) {
            t2 = headA;
        }else{
            t2 = t2->next;
        }
    }
    
    return t1;
}

void _facetest_0207_test(){
    ListNode node1(1);
    ListNode node2(1);
    ListNode node3(8);
    ListNode node4(4);
    ListNode node5(5);
    
    ListNode node6(5);
    ListNode node7(0);
    
    
//    node1.next = &node2;
//    node2.next = &node3;
//    node3.next = &node4;
//    node4.next = &node5;
//
//    node6.next = &node7;
//    node7.next = &node2;
    
    ListNode *res = getIntersectionNode2(&node1,&node2);
    
}
