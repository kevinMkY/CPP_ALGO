//
//  572_另一个树的子树.cpp
//  testC++++
//
//  Created by yekaihua on 2020/12/27.
//

#include "572_另一个树的子树.hpp"
#include "common.h"

//给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。
//
//示例 1:
//给定的树 s:
//
//     3
//    / \
//   4   5
//  / \
// 1   2
//给定的树 t：
//
//   4
//  / \
// 1   2
//返回 true，因为 t 与 s 的一个子树拥有相同的结构和节点值。
//
//示例 2:
//给定的树 s：
//
//     3
//    / \
//   4   5
//  / \
// 1   2
//    /
//   0
//给定的树 t：
//
//   4
//  / \
// 1   2
//返回 false。
//
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/subtree-of-another-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

bool isSubtree1isSametree1(TreeNode* s, TreeNode* t) {
    if (!s && !t) { //同时不存在,相等
        return true;
    }
    if (s && t) {   //同时存在,则左右也一定相等
        return s->val == t->val
        && isSubtree1isSametree1(s->left, t->left)
        && isSubtree1isSametree1(s->right, t->right);
    }
    return false;
}

//递归---两棵树是子树,要么相等,要么是左子树的子树,要么是右子树的子树
bool isSubtree1(TreeNode* s, TreeNode* t) {
    if (!s && !t) {
        return true;
    }else if(!t){
        return true;
    }else if(!s){
        return false;
    }
    bool issame = isSubtree1isSametree1(s, t);
    bool issubleft = isSubtree1(s->left, t);
    bool issubright = isSubtree1(s->right, t);
    return issame || issubleft || issubright;
    }

//迭代--双指针
bool isSubtree2(TreeNode* s, TreeNode* t) {
    bool res;
    stack<TreeNode *>stack1;
    stack<TreeNode *>stack2;
    while (s || stack1.size()) {
        while (s) {
            stack1.push(s);
            s = s->left;
        }
        s = stack1.top();
        stack1.pop();
        s = s->right;
    }
    return res;
    }

void _572_test()
{
    vector<int> list1 = {3,4,5,1,2};
    vector<int> list2 = {4,1,2};
    TreeNode *node1 = initTreeWithNULLVector(list1);
    TreeNode *node2 = initTreeWithNULLVector(list2);
    
    bool res1 = isSubtree1(node1,node2);
    bool res2 = isSubtree2(node1,node2);
    
}
