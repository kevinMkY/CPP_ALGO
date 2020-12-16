//
//  589_N叉树的前序遍历.cpp
//  testC++++
//
//  Created by ykh on 2020/9/23.
//

#include "589_N叉树的前序遍历.hpp"
#include "common.h"
#include "Node.hpp"
//
//给定一个 N 叉树，返回其节点值的前序遍历。
//
//例如，给定一个 3叉树 :
//
//
//
//
//
//
//
//返回其前序遍历: [1,3,5,6,2,4]。
//
//
//
//说明: 递归法很简单，你可以使用迭代法完成此题吗?
//
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//递归
vector<int> preorder1(Node* root) {

    vector<int> res;
    if (root == nullptr) {
        return res;
    }
    
    res.push_back(root->val);
    for (int i = 0; i<root->children.size(); i++) {
        Node* child = root->children[i];
        vector<int> resChild = preorder1(child);
        for (int j = 0; j<resChild.size(); j++) {
            int val = resChild[j];
            res.push_back(val);
        }
    }
    
    return res;
    }

//迭代
vector<int> preorder2(Node* root) {

    vector<int> res;
    if (root == nullptr) {
        return res;
    }
    
    stack<Node *> mystack;
    mystack.push(root);
    
    while (!mystack.empty()) {
        Node *node = mystack.top();
        res.push_back(node->val);
        mystack.pop();
        int size = node->children.size();
        for (int i = size-1; i>=0; i--) {
            Node *childNode = node->children[i];
            if (childNode != nullptr) {
                mystack.push(childNode);
            }
        }
    }
    
    return res;
}

void _589_test(){
    
    
//    vector<int> list1 = {4,2,7,1,3,6,9};
    vector<int> list2 = {1,NULL,3,2,4,NULL,5,6};
//    Node *node1 = initNXTreeWithVector(list1);
    Node *node2 = initNXTreeWithVector(list2);
        
    vector<int> res1 = preorder1(node2);
    vector<int> res2 = preorder1(node2);
    
}

