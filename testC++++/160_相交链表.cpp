//
//  160_相交链表.cpp
//  testC++++
//
//  Created by ykh on 2020/9/14.
//

#import "160_相交链表.hpp"
#import "common.h"

//编写一个程序，找到两个单链表相交的起始节点。
//
//如下面的两个链表：
//
//
//
//在节点 c1 开始相交。
//
//
//
//示例 1：
//
//
//
//输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
//输出：Reference of the node with value = 8
//输入解释：相交节点的值为 8 （注意，如果两个链表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
//
//
//示例 2：
//
//
//
//输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
//输出：Reference of the node with value = 2
//输入解释：相交节点的值为 2 （注意，如果两个链表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
//
//
//示例 3：
//
//
//
//输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
//输出：null
//输入解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
//解释：这两个链表不相交，因此返回 null。
//
//
//注意：
//
//如果两个链表没有交点，返回 null.
//在返回结果后，两个链表仍须保持原有的结构。
//可假定整个链表结构中没有循环。
//程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/intersection-of-two-linked-lists
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//让A和B走一样长的路程--->双指针
ListNode *_160_testgetIntersectionNode1(ListNode *headA, ListNode *headB) {
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

//尾部对齐
ListNode *_160_testgetIntersectionNode2(ListNode *headA, ListNode *headB) {

    if (headA == nullptr) {
            return nullptr;
        }
        if (headB == nullptr) {
            return nullptr;
        }
        
        int sizeA = 0;
        int sizeB = 0;
        
        ListNode *curA = headA;
        ListNode *curB = headB;
        while (curA !=nullptr) {
            curA = curA->next;
            sizeA++;
        }
        while (curB !=nullptr) {
            curB = curB->next;
            sizeB++;
        }
        
        int modify = sizeA - sizeB;
        ListNode *res;
        curA = headA;
        curB = headB;
        if (modify > 0) {
            res = curA;
            for (int i = 0; i < sizeA; i++) {
                
                if (i < modify) {
                    curA = curA->next;
                    res = res->next;
                }else{
                    if (curA != curB) {
                        res = curA->next;
                    }
                    curA = curA->next;
                    curB = curB->next;
                }
            }
        }else{
            res = curB;
            modify= -modify;
            for (int i = 0; i < sizeB; i++) {
                if (i < modify) {
                    curB = curB->next;
                    res = res->next;
                }else{
                    if (curA != curB) {
                        res = curB->next;
                    }
                    curA = curA->next;
                    curB = curB->next;
                }
            }
        }

        return res;
}

//如果相交,则必然尾巴开始倒数某几个节点是一致的
//[ A ][ b ][ c ][ d ]
//[ g ][ c ][ d ]
//--->假如把b拼到a后面,a也拼到b后面,则,某一时刻,他们必然尾部对齐,如果一直没有,则说明不相交
//[ A ][ b ][ c ][ d ]      [ g ][ c ][ d ]
//[ g ][ c ][ d ]      [ A ][ b ][ c ][ d ]
ListNode *_160_testgetIntersectionNode3(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) return nullptr;
    ListNode *curA = headA;
    ListNode *curB = headB;
    ListNode *res = nullptr;
    bool alreadyComA = false;
    bool alreadyComB = false;
    while (curA && curB) {
        if (curA == curB && curA) {
            if (!res) {
                res = curA;
            }
        }else{
            res = nullptr;
        }
        curA = curA->next;
        curB = curB->next;
        
        if (curA == nullptr) {
            if (!alreadyComA) {
                curA = headB;
                alreadyComA = true;
            }
        }
        if (curB == nullptr) {
            if (!alreadyComB) {
                curB = headA;
                alreadyComB = true;
            }
        }
    }
    return res;
}

ListNode *_160_testgetIntersectionNode4(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) return nullptr;
    
    ListNode *cura = headA,*curb = headB;
    while (cura != curb) {
        cura = (cura == nullptr)?headB:cura->next;
        curb = (curb == nullptr)?headA:curb->next;
    }
    return cura;
}

void _160_test(){
    ListNode node1(2);
    ListNode node2(6);
    ListNode node3(4);
//    ListNode node4();
//    ListNode node5(5);
    
    ListNode node6(1);
    ListNode node7(5);
//    ListNode node8(5);
    
    
    node1.next = &node2;
    node2.next = &node3;
//    node3.next = &node4;
//    node4.next = &node5;

    node6.next = &node7;
//    node7.next = &node2;
    
    ListNode *res = _160_testgetIntersectionNode4(&node6,&node2);
    
}
