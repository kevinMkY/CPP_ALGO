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

vector<int> postorder1(Node* root) {

    vector<int>  res;
    
    return res;
    }

//迭代
//后xu-->左右中
//前序-->中左右-->中右左-->左右中
vector<int> postorder2(Node* root) {

    vector<int>  res;
    
    reverse(res.begin(), res.end());
    
    return res;
    }

void _590_test(){
    
//    vector<int> list1 = {4,2,7,1,3,6,9};
    vector<int> list2 = {1,NULL,3,2,4,NULL,5,6};
//    Node *node1 = initNXTreeWithVector(list1);
    Node *node2 = initNXTreeWithVector(list2);
    
    vector<int> res3 = postorder1(node2);
    vector<int> res4 = postorder2(node2);
    
}

