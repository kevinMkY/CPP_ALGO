//
//  138_复制带随机指针的链表.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/17.
//

#include "138_复制带随机指针的链表.hpp"
#include "common.h"
#include "Node.hpp"

//给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，该指针可以指向链表中的任何节点或空节点。
//
//构造这个链表的 深拷贝。 深拷贝应该正好由 n 个 全新 节点组成，其中每个新节点的值都设为其对应的原节点的值。新节点的 next 指针和 random 指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。复制链表中的指针都不应指向原链表中的节点 。
//
//例如，如果原链表中有 X 和 Y 两个节点，其中 X.random --> Y 。那么在复制链表中对应的两个节点 x 和 y ，同样有 x.random --> y 。
//
//返回复制链表的头节点。
//
//用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：
//
//val：一个表示 Node.val 的整数。
//random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。
//你的代码 只 接受原链表的头节点 head 作为传入参数。
//
//
//
//示例 1：
//
//
//
//输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
//输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
//示例 2：
//
//
//
//输入：head = [[1,1],[2,1]]
//输出：[[1,1],[2,1]]
//示例 3：
//
//
//
//输入：head = [[3,null],[3,0],[3,null]]
//输出：[[3,null],[3,0],[3,null]]
//示例 4：
//
//输入：head = []
//输出：[]
//解释：给定的链表为空（空指针），因此返回 null。
//
//
//提示：
//
//0 <= n <= 1000
//-10000 <= Node.val <= 10000
//Node.random 为空（null）或指向链表中的节点。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/copy-list-with-random-pointer
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

Node* copyRandomList(Node* head) {
    if (!head) return head;
    
    Node *cur = head;
    
    //创建新node,放在老node旁边
    while (cur) {
        Node *orginNext = cur->next;
        Node *cloned = new Node(cur->val,nullptr);
        cur->next = cloned;
        cloned->next = orginNext;
        cur = orginNext;
    }
    //更新random
    cur = head;
    while (cur) {
        Node *cloned = cur->next;
        cloned->random = cur->random;
        cur = cloned->next;
    }
    //更新next
    cur = head;
    Node *orginCloned = cur->next;
    //todo
    
    
    return orginCloned;
}


Node* copyRandomList1(Node* head) {
    if (head == nullptr) {
        return head;
    }
    map<Node *, Node *>nodeMap;
    Node *cur = head;
    Node *newHead = new Node(0);
    Node *pre = newHead;
    while (cur) {
        Node *cloned = new Node(cur->val,nullptr);
        pre->next = cloned;
        nodeMap[cur] = cloned;
        pre = pre->next;
        cur = cur->next;
    }
    cur = head;
    pre = newHead;
    while (cur) {
        Node *cloned = pre->next;
        cloned->random = nodeMap[cur->random];
        cur = cur->next;
        pre = pre->next;
    }
    
    return newHead->next;
}

void _138_test()
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
    Node*res= copyRandomList1(&node1);
    
}
