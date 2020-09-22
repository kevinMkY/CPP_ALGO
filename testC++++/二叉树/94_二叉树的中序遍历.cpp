//
//  94_二叉树的中序遍历.cpp
//  testC++++
//
//  Created by ykh on 2020/9/22.
//

#include "94_二叉树的中序遍历.hpp"
#include "common.h"

//给定一个二叉树，返回它的中序 遍历。
//
//示例:
//
//输入: [1,null,2,3]
//   1
//    \
//     2
//    /
//   3
//
//输出: [1,3,2]
//进阶: 递归算法很简单，你可以通过迭代算法完成吗？
//
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//中序--->左中右

//递归
vector<int> inorderTraversal1(TreeNode* root) {

    vector<int> res;
    if (root == nullptr) {
        return res;
    }
    
    vector<int> leftres = inorderTraversal1(root->left);
    
    vector<int> rightres = inorderTraversal1(root->right);
    
    for (int i = 0; i<leftres.size(); i++) {
        res.push_back(leftres[i]);
    }
    res.push_back(root->val);
    for (int i = 0; i<rightres.size(); i++) {
        res.push_back(rightres[i]);
    }
    
    return res;
    }

//迭代
//左中右
vector<int> inorderTraversal2(TreeNode* root) {

    vector<int> res;
    if (root == nullptr) {
        return res;
    }
    
    stack<TreeNode *> stk;
    TreeNode * node = root;
    while (!stk.empty() || node) {
        if (node) {         //先沿着左子树一直走下去
            //不断往左子树方向走，每走一次就将当前节点保存到栈中
                        //这是模拟递归的调用
            stk.push(node);
            node = node->left;
        }else{
            //当前节点为空，说明左边走到头了，从栈中弹出节点并保存
                        //然后转向右边节点，继续上面整个过程
            //当前node = null
            TreeNode *tmp = stk.top();
            stk.pop();
            res.push_back(tmp->val);
            node = tmp->right;
        }
    }
    
    return res;
    }

vector<int> inorderTraversal3(TreeNode* root) {

    vector<int> res;
    if (root == nullptr) {
        return res;
    }
    return res;
    }

void _94_test(){
    
    
    vector<int> list1 = {4,2,7,1,3,6,9};
    vector<int> list2 = {1,NULL,2,3};
    TreeNode *node1 = initTreeWithVector(list1);
    TreeNode *node2 = initTreeWithVector(list2);
//    TreeNode *node1 = initTreeWithVector(list1);
    
//    vector<int> res1 = inorderTraversal1(node1);
//    vector<int> res2 = inorderTraversal1(node2);
    vector<int> res3 = inorderTraversal2(node1);
    vector<int> res4 = inorderTraversal2(node2);
//    vector<int> res5 = inorderTraversal3(node1);
//    vector<int> res6 = inorderTraversal3(node2);
    
}
