//
//  1123_最深叶节点的最近公共祖先.cpp
//  testC++++
//
//  Created by yekaihua on 2021/1/5.
//

#include "1123_最深叶节点的最近公共祖先.hpp"
#include "common.h"

//给你一个有根节点的二叉树，找到它最深的叶节点的最近公共祖先。
//
//回想一下：
//
//叶节点 是二叉树中没有子节点的节点
//树的根节点的 深度 为 0，如果某一节点的深度为 d，那它的子节点的深度就是 d+1
//如果我们假定 A 是一组节点 S 的 最近公共祖先，S 中的每个节点都在以 A 为根节点的子树中，且 A 的深度达到此条件下可能的最大值。
//
//
//注意：本题与力扣 865 重复：https://leetcode-cn.com/problems/smallest-subtree-with-all-the-deepest-nodes/
//
//
//
//示例 1：
//
//
//输入：root = [3,5,1,6,2,0,8,null,null,7,4]
//输出：[2,7,4]
//解释：
//我们返回值为 2 的节点，在图中用黄色标记。
//在图中用蓝色标记的是树的最深的节点。
//注意，节点 6、0 和 8 也是叶节点，但是它们的深度是 2 ，而节点 7 和 4 的深度是 3 。
//示例 2：
//
//输入：root = [1]
//输出：[1]
//解释：根节点是树中最深的节点，它是它本身的最近公共祖先。
//示例 3：
//
//输入：root = [0,1,3,null,2]
//输出：[2]
//解释：树中最深的叶节点是 2 ，最近公共祖先是它自己。
//
//
//提示：
//
//给你的树中将有 1 到 1000 个节点。
//树中每个节点的值都在 1 到 1000 之间。
//每个节点的值都是独一无二的。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/lowest-common-ancestor-of-deepest-leaves
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

TreeNode* lcaDeepestLeaves1test(TreeNode* root,int &depth) {
    if (!root) {
        return root;
    }
    depth++;
    int leftdepth = depth;
    int rightdepth = depth;
    auto leftnode =lcaDeepestLeaves1test(root->left, leftdepth);
    auto rightnode =lcaDeepestLeaves1test(root->right, rightdepth);
    if(leftdepth > rightdepth){         //左边更深
        depth = leftdepth;
        return leftnode;
    }else if(leftdepth < rightdepth){   //右边更深
        depth = rightdepth;
        return rightnode;
    }else{                              //左 == 右
        depth = leftdepth;
        return root;
    }
}

//递归
TreeNode* lcaDeepestLeaves1(TreeNode* root) {
    TreeNode* res = nullptr;
    if (!root) {
        return res;
    }
    int depth = 1;
    res = lcaDeepestLeaves1test(root,depth);
    return res;
    }

void _1123_test()
{
    vector<int> list1 = {3,5,1,6,2,0,8,NULL,NULL,7,4};
    vector<int> list2 = {1,2,4,NULL,3};
    TreeNode *node1 = initTreeWithNULLVector(list1);
    TreeNode *node2 = initTreeWithNULLVector(list2);
    TreeNode *node3 = initTreeWithNULLVector(list1);
    TreeNode *node4 = initTreeWithNULLVector(list2);
    
    TreeNode* res1 = lcaDeepestLeaves1(node1);
    TreeNode* res2 = lcaDeepestLeaves1(node2);
    
}
