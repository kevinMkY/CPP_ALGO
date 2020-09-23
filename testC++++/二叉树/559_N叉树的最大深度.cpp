//
//  559_N叉树的最大深度.cpp
//  testC++++
//
//  Created by ykh on 2020/9/23.
//

#include "559_N叉树的最大深度.hpp"
#include "common.h"

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

void _559_test(){
    
    
    vector<int> list1 = {4,2,7,1,3,6,9};
    vector<int> list2 = {3,9,20,NULL,NULL,15,7};    //注意,这个带NULL的数据生成的tree是与题目不符的
    TreeNode *node1 = initTreeWithVector(list1);
    TreeNode *node2 = initTreeWithNULLVector(list2);
//    TreeNode *node1 = initTreeWithVector(list1);
    
//    int res1 = maxDepth1(node1);
//    int res2 = maxDepth1(node2);
    
//    int res3 = maxDepth2(node1);
//    int res4 = maxDepth2(node2);
    
}

