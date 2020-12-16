//
//  590_N叉树的后序遍历.cpp
//  testC++++
//
//  Created by ykh on 2020/9/23.
//

#include "590_N叉树的后序遍历.hpp"
#include "common.h"
#include "Node.hpp"

//给定一个 N 叉树，返回其节点值的后序遍历。
//
//例如，给定一个 3叉树 :
//
//
//
//
//
//
//
//返回其后序遍历: [5,6,3,2,4,1].
//
//
//
//说明: 递归法很简单，你可以使用迭代法完成此题吗?
//
//通过次数35,877提交次数47,993
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//递归
vector<int> postorder1(Node* root) {

    vector<int>  res;
    if (root == nullptr) {
        return res;
    }
    
    int size = root->children.size();
    for (int i = 0; i<size; i++) {
        Node *child = root->children[i];
        vector<int> childRes = postorder1(child);
        int childsize = childRes.size();
        for (int j = 0; j<childsize; j++) {
            int val = childRes[j];
            res.push_back(val);
        }
    }
    
    res.push_back(root->val);
    
    return res;
    }

//迭代
//后xu-->左右中
//前序-->中左右-->中右左-->左右中
vector<int> postorder2(Node* root) {

    vector<int>  res;
    if (root == nullptr) {
        return res;
    }
    
    stack<Node *> mystakc;
    mystakc.push(root);
    
    while (!mystakc.empty()) {
        Node *node = mystakc.top();
        mystakc.pop();
        res.push_back(node->val);  //中1
        int size = node->children.size();
        for (int i = 0 ; i<size; i++) {
            Node *child = node->children[i];    //左先进后出,所以左3右2
            mystakc.push(child);
        }
    }
    
    //此时res中右左,reverse一下就是左右中
    reverse(res.begin(), res.end());
    
    return res;
    }

void _590_test(){
    
    //多叉树不含null的生成方法是错的
//    vector<int> list1 = {4,2,7,1,3,6,9};
    vector<int> list2 = {1,NULL,3,2,4,NULL,5,6};
//    Node *node1 = initNXTreeWithVector(list1);
    Node *node2 = initNXTreeWithVector(list2);
    
    vector<int> res3 = postorder1(node2);
    vector<int> res4 = postorder2(node2);
    
}

