//
//  889_根据前序和后序遍历构造二叉树.cpp
//  testC++++
//
//  Created by ykh on 2020/9/23.
//

#include "889_根据前序和后序遍历构造二叉树.hpp"
#include "common.h"

//返回与给定的前序和后序遍历匹配的任何二叉树。
//
// pre 和 post 遍历中的值是不同的正整数。
//
//
//
//示例：
//
//输入：pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
//输出：[1,2,3,4,5,6,7]
//
//
//提示：
//
//1 <= pre.length == post.length <= 30
//pre[] 和 post[] 都是 1, 2, ..., pre.length 的排列
//每个输入保证至少有一个答案。如果有多个答案，可以返回其中一个。
//通过次数7,201提交次数10,854
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

void _889_test(){
    
    
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

