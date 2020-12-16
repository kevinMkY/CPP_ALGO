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

bool check(TreeNode *left,TreeNode *right){
    if (left == nullptr) {
        if (right !=nullptr) {
            return false;
        }else{
            return true;
        }
    }else if (right == nullptr){
        return false;
    }else{
        bool res1 = check(left->left, right->right);
        bool res2 = check(left->right, right->left);
        bool res3 = left->val == right->val;
        
        return res1 && res2 && res3;
    }
}

//递归-镜像对称-->双指针,分别指向左右
bool isSymmetric1(TreeNode* root) {
    return check(root, root);
}

//迭代-用队列同时入队左右
bool isSymmetric2(TreeNode* root) {
    bool res = true;
    if (!root) {
        return res;
    }
    queue<TreeNode *>myqueue;
    myqueue.push(root);
    myqueue.push(root);
    while (!myqueue.empty()) {
        TreeNode *left = myqueue.front();
        myqueue.pop();
        TreeNode *right = myqueue.front();
        myqueue.pop();
        if (!left && !right) {
            continue;
        }else if (!left && right){
            res = false;
            break;
        }else if (left && !right){
            res = false;
            break;
        }else{
            if (left->val != right->val) {
                res = false;
                break;
            }else{
                myqueue.push(left->left);
                myqueue.push(right->right);
                myqueue.push(left->right);
                myqueue.push(right->left);
            }
        }
    }
    return res;
}

void _101_test(){
    
    vector<int> list1 = {1,2,2,3,4,4,3};
    vector<int> list2 = {1,2,2,NULL,3,NULL,3};
    TreeNode *node1 = initTreeWithNULLVector(list1);
    TreeNode *node2 = initTreeWithNULLVector(list2);
    
    bool res1 = isSymmetric1(node1);
    bool res2 = isSymmetric1(node2);
    bool res3 = isSymmetric2(node1);
    bool res4 = isSymmetric2(node2);
    

}
