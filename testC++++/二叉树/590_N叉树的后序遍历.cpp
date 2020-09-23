//
//  590_N叉树的后序遍历.cpp
//  testC++++
//
//  Created by ykh on 2020/9/23.
//

#include "590_N叉树的后序遍历.hpp"
#include "common.h"


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

void _590_test(){
    
    
    vector<int> list1 = {4,2,7,1,3,6,9};
    vector<int> list2 = {3,9,20,NULL,NULL,15,7};
    TreeNode *node1 = initTreeWithVector(list1);
    TreeNode *node2 = initTreeWithNULLVector(list2);
//    TreeNode *node1 = initTreeWithVector(list1);
    
//    int res1 = maxDepth1(node1);
//    int res2 = maxDepth1(node2);
    
//    int res3 = maxDepth2(node1);
//    int res4 = maxDepth2(node2);
    
}

