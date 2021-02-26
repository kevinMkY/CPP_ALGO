//
//  剑指 Offer 36.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/26.
//

#include "剑指 Offer 36. 二叉搜索树与双向链表.hpp"
#include "common.h"
#include "Node.hpp"

Node*pre,*head;

void dfs(Node *cur){
    if (cur == nullptr) {
        return;
    }
    dfs(cur->left);
    //
    if (pre) {
        pre->right = cur;
        cur->left = pre;
    }else{
        head = cur;
    }
    pre = cur;
    //
    dfs(cur->right);
}

Node* treeToDoublyList(Node* root) {
     
    if (!root) {
        return nullptr;
    }
    dfs(root);
    
    pre->right = head;
    head->left = pre;
    return head;
    }

void _offer_36_repeat_test()
{
    Node*node1 = new Node(4);
    Node*node2 = new Node(2);
    Node*node3 = new Node(5);
    Node*node4 = new Node(1);
    Node*node5 = new Node(3);
    node4->left = node2;
    node4->right = node5;
    node2->left = node1;
    node2->right = node3;
    Node*res = treeToDoublyList(node4);
    
}
