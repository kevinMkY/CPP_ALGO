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

//递归
bool isSymmetric1(TreeNode* root) {
    
    return false;
    }

//迭代
bool isSymmetric2(TreeNode* root) {
    
    
    
    return false;
}

void _101_test(){
    
    vector<int> list1 = {1,2,2,3,4,4,3};
    vector<int> list2 = {1,2,2,NULL,3,NULL,3};
    TreeNode *node1 = initTreeWithVector(list1);
    TreeNode *node2 = initTreeWithNULLVector(list2);
    
    bool res1 = isSymmetric1(node1);
    bool res2 = isSymmetric2(node1);
    

}
