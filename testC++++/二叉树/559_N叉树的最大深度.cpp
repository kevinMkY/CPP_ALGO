//
//  559_N叉树的最大深度.cpp
//  testC++++
//
//  Created by ykh on 2020/9/23.
//

#import "559_N叉树的最大深度.hpp"
#import "common.h"
#import "Node.hpp"

//给定一个 N 叉树，找到其最大深度。
//
//最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。
//
//例如，给定一个 3叉树 :
//
//
//
//
//
//
//
//我们应返回其最大深度，3。
//
//说明:
//
//树的深度不会超过 1000。
//树的节点总不会超过 5000。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/maximum-depth-of-n-ary-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//递归
int maxDepth1(Node* root) {
    
    int h = 0;
    if (root == nullptr) {
        return h;
    }
    
    int size = root->children.size();
    for (int i = 0; i<size; i++) {
        Node *child = root->children[i];
        int childh = maxDepth1(child);
        h = max(h, childh);
    }
    
    return h + 1;
    }

//迭代-->层序
int maxDepth2(Node* root) {
    
    int h = 0;
    if (root == nullptr) {
        return h;
    }
    
    queue<Node *> myqueue;
    myqueue.push(root);
    int size = 1;
    
    while (!myqueue.empty()) {
        Node *node = myqueue.front();
        myqueue.pop();
        size--;
        int childsize = node->children.size();
        for (int i = 0; i<childsize; i++) {
            Node *child = node->children[i];
            myqueue.push(child);
        }
        if (size == 0) {    //当前层完毕
            size = myqueue.size();
            h++;
        }
    }
    return h;
    }

void _559_test(){
    
    
//    vector<int> list1 = {4,2,7,1,3,6,9};
    vector<int> list2 = {1,NULL,3,2,4,NULL,5,6};
//    Node *node1 = initNXTreeWithVector(list1);
    Node *node2 = initNXTreeWithVector(list2);
    
    int res3 = maxDepth1(node2);
    int res4 = maxDepth2(node2);
    
}

