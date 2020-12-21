//
//  897_递增顺序查找树.cpp
//  testC++++
//
//  Created by yekaihua on 2020/12/19.
//

#include "897_递增顺序查找树.hpp"
#include "common.h"

//给你一个树，请你 按中序遍历 重新排列树，使树中最左边的结点现在是树的根，并且每个结点没有左子结点，只有一个右子结点。
//
//
//
//示例 ：
//
//输入：[5,3,6,2,4,null,8,1,null,null,null,7,9]
//
//       5
//      / \
//    3    6
//   / \    \
//  2   4    8
// /        / \
//1        7   9
//
//输出：[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
//
// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
//          \
//           6
//            \
//             7
//              \
//               8
//                \
//                 9
//
//
//提示：
//
//给定树中的结点数介于 1 和 100 之间。
//每个结点都有一个从 0 到 1000 范围内的唯一整数值。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/increasing-order-search-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//递归
TreeNode* increasingBST1(TreeNode* root) {

    TreeNode* res = nullptr;
    if (root == nullptr) {
        return res;
    }
    auto left = increasingBST1(root->left);
    auto right = increasingBST1(root->right);
    if (left) {
        res = left;
        auto last = left;
        while (left) {
            last = left;
            left = left->right;
        }
        last->right = root;
        last->left = nullptr;
    }else{
        res = root;
    }
    root->left = nullptr;
    root->right = right;
    if (right) {
        right->left = nullptr;
    }
    
    return res;
    }

//迭代
TreeNode* increasingBST2(TreeNode* root) {
    TreeNode* res = nullptr;
    if (root == nullptr) {
        return res;
    }
    queue<TreeNode *>myqueue;
    stack<TreeNode *>mystack;
    while (root || !mystack.empty()) {
        while (root) {
            mystack.push(root);
            root = root->left;
        }
        root = mystack.top();
        mystack.pop();
        myqueue.push(root);
        root = root->right;
    }
    res = myqueue.front();
    TreeNode *last = nullptr;
    while (!myqueue.empty()) {
        auto node = myqueue.front();
        myqueue.pop();
        node->left = nullptr;
        node->right = nullptr;
        if (last) {
            last->right = node;
        }
        last = node;
    }
    return res;
    }

void _897_test()
{
    vector<int> list1 = {5,3,6,2,4,NULL,8,1,NULL,NULL,NULL,7,9};
    vector<int> list2 = {212};
    //这个构造方法遇到连续null会出bug,导致生成节点不对
    TreeNode *node1 = initTreeWithNULLVector(list1);
    TreeNode *node2 = initTreeWithNULLVector(list2);
    
    TreeNode *res1 = increasingBST1(node1);
    TreeNode *res2 = increasingBST2(node1);
    TreeNode *res3 = increasingBST1(node2);
    TreeNode *res4 = increasingBST2(node2);
    
}
