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

Node* _offer_35_repeat_testcopyRandomList3(Node* head) {
    
    if (!head) {
        return head;
    }
    
    //copy 放到右边
    
    Node *cur = head;
    while (cur ) {
        Node *cloned = new Node(cur->val);
        cloned->next = cur->next;
        cur->next = cloned;
        cur = cloned->next;
    }
    
    //设置random
    cur = head;
    
    while (cur) {
        Node *cloned = cur->next;
        if (!cloned) {
            break;
        }
        cloned->random = cur->random?cur->random->next:nullptr;
        cur = cloned->next;
    }
    //断开链接
    cur = head;
    Node *clonedHead = nullptr;
    while (cur) {
        Node *cloned = cur->next;
        if (!cloned) {
            break;
        }
        if (!clonedHead) {
            clonedHead = cloned;
        }
        cur->next = cloned->next;
        cur = cur->next;
        cloned->next = cur?cur->next:nullptr;
    }
    return clonedHead;
}

Node* _offer_35_repeat_testcopyRandomList4(Node* head) {
    if (!head) {
        return head;
    }
    
    Node *cur = head;
    Node *clonedhead = new Node(0);
    Node *clonedcur = clonedhead;
    map<Node *, Node *>mymap;
    while (cur) {
        Node *cloned = new Node(cur->val);
        mymap[cur] = cloned;
        clonedcur->next = cloned;
        clonedcur = clonedcur->next;
        cur = cur->next;
    }
    clonedcur = clonedhead->next;
    cur = head;
    while (cur) {
        if (cur->random) {
            clonedcur->random = mymap[cur->random];
        }

        clonedcur = clonedcur->next;
        cur = cur->next;
    }
    
    return clonedhead->next;
}

void _offer_35_repeat_test()
{
    Node node1(7,NULL);
    Node node2(13,&node1);
    Node node5(1,&node1);
    Node node3(11,&node5);
    Node node4(10,&node3);
    
    
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    Node*res2= _offer_35_repeat_testcopyRandomList4(&node1);
    
    Node node11(-1,NULL);
    Node*res4= _offer_35_repeat_testcopyRandomList4(&node11);
    
}
