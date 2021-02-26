//
//  剑指 Offer 35.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/26.
//

#include "剑指 Offer 35. 复杂链表的复制.hpp"
#include "common.h"
#include "Node.hpp"

//
Node* _offer_35_repeat_testcopyRandomList1(Node* head) {
        
    if (!head) {
        return head;
    }
    map<Node *,Node *>mymap;
    Node *cur = head;
    Node *clonedHead =new Node(0);
    Node *clonedCur = clonedHead;
    //
    while (cur) {
        Node *cloned = new Node(cur->val);
        mymap[cur] = cloned;
        clonedCur->next = cloned;
        clonedCur = cloned;
        cur = cur->next;
    }
    //
    cur = head;
    clonedCur = clonedHead->next;
    while (cur) {
        clonedCur->random = mymap[cur->random];
        clonedCur = clonedCur->next;
        cur = cur->next;
    }
    return clonedHead->next;
    }

void _offer_35_repeat_test()
{
    Node node2(2,&node2);
    Node node1(1,&node2);
    
//    Node node5(1,&node1);
//    Node node3(11,&node2);
//    Node node4(10,&node3);
    
    node1.next = &node2;
//    node2.next = &node3;
//    node3.next = &node4;
//    node4.next = &node5;
    Node*res= _offer_35_repeat_testcopyRandomList1(&node1);
    
}
