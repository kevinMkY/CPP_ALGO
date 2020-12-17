//
//  226_翻转二叉树.cpp
//  testC++++
//
//  Created by ykh on 2020/9/22.
//

#include "226_翻转二叉树.hpp"
#include "common.h"

//翻转一棵二叉树。
//
//示例：
//
//输入：
//
//     4
//   /   \
//  2     7
// / \   / \
//1   3 6   9
//输出：
//
//     4
//   /   \
//  7     2
// / \   / \
//9   6 3   1
//备注:
//这个问题是受到 Max Howell 的 原问题 启发的 ：
//
//谷歌：我们90％的工程师使用您编写的软件(Homebrew)，但是您却无法在面试时在白板上写出翻转二叉树这道题，这太糟糕了。
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/invert-binary-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//递归--对节点的操作放在递归的前/中/后,分别算是前序/中序/后序三种
TreeNode* invertTree1(TreeNode* root) {
    if (!root) {
        return root;
    }
    
    TreeNode *left = root->left;
    TreeNode *right = root->right;
    root->left = invertTree1(right);
    root->right = invertTree1(left);
    
    return root;
    }

//迭代-dfs
TreeNode* invertTree2(TreeNode* root) {
    if (!root) {
        return root;
    }
    
    stack<TreeNode *>mystack;
    TreeNode* temp = root;
    while (root || !mystack.empty()) {
        while (root) {
            mystack.push(root);
            root = root->left;
        }
        root = mystack.top();
        mystack.pop();
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        root->left = right;
        root->right = left;
        root = right;
    }
    
    return temp;
    }

void _226_test(){
    
    vector<int> list1 = {4,2,7,1,3,6,9};
    TreeNode *node1 = initTreeWithVector(list1);
    TreeNode *node2 = initTreeWithVector(list1);
    TreeNode* res1 = invertTree1(node1);
    TreeNode* res2 = invertTree2(node2);

}
