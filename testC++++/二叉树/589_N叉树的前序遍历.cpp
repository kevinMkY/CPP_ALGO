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
    
    
    return res;
    }

//迭代
vector<int> preorder2(Node* root) {

    vector<int> res;
    
    
    return res;
}

void _589_test(){
    
    
    vector<int> list1 = {4,2,7,1,3,6,9};
    vector<int> list2 = {1,NULL,3,2,4,NULL,5,6};
    Node *node1 = initNXTreeWithVector(list1);
    Node *node2 = initNXTreeWithVector(list2);
    
    vector<int> res3 = preorder2(node2);
    
}

