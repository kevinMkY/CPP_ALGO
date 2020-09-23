//
//  101_对称二叉树.cpp
//  testC++++
//
//  Created by ykh on 2020/9/23.
//

#include "101_对称二叉树.hpp"
#include "common.h"

//给定一个二叉树，检查它是否是镜像对称的。
//
//
//
//例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
//
//    1
//   / \
//  2   2
// / \ / \
//3  4 4  3
//
//
//但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
//
//    1
//   / \
//  2   2
//   \   \
//   3    3
//
//
//进阶：
//
//你可以运用递归和迭代两种方法解决这个问题吗？
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/symmetric-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

void _101_test(){
    
    
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
