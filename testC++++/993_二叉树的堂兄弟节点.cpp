//
//  993_二叉树的堂兄弟节点.cpp
//  testC++++
//
//  Created by yekaihua on 2020/12/27.
//

#include "993_二叉树的堂兄弟节点.hpp"
#include "common.h"

//在二叉树中，根节点位于深度 0 处，每个深度为 k 的节点的子节点位于深度 k+1 处。
//
//如果二叉树的两个节点深度相同，但父节点不同，则它们是一对堂兄弟节点。
//
//我们给出了具有唯一值的二叉树的根节点 root，以及树中两个不同节点的值 x 和 y。
//
//只有与值 x 和 y 对应的节点是堂兄弟节点时，才返回 true。否则，返回 false。
//
//
//
//示例 1：
//
//
//输入：root = [1,2,3,4], x = 4, y = 3
//输出：false
//示例 2：
//
//
//输入：root = [1,2,3,null,4,null,5], x = 5, y = 4
//输出：true
//示例 3：
//
//
//
//输入：root = [1,2,3,null,4], x = 2, y = 3
//输出：false
//
//
//提示：
//
//二叉树的节点数介于 2 到 100 之间。
//每个节点的值都是唯一的、范围为 1 到 100 的整数。
//
//
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/cousins-in-binary-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

vector<int> depths = {};
vector<TreeNode *> parnodes = {};

void isCousins1digui(TreeNode *root,int depth,int target){
    if (!root) {
        return;
    }
    if (root->left) {
        if (root->left->val == target) {
            depths.push_back(depth+1);
            parnodes.push_back(root);
        }
        isCousins1digui(root->left, depth+1, target);
    }
    if (root->right) {
        if (root->right->val == target) {
            depths.push_back(depth+1);
            parnodes.push_back(root);
        }
        isCousins1digui(root->right, depth+1, target);
    }
}
//递归
bool isCousins1(TreeNode* root, int x, int y) {
    bool res;
    if (!root) {
        return false;
    }
    isCousins1digui(root,0,x);
    isCousins1digui(root,0,y);
    if (depths.size() < 2 || parnodes.size() < 2) {
        return false;
    }
    bool depthdiff = (depths[0] == depths[1]);
    bool parnodesdiff = (parnodes[0] != parnodes[1]);
    return depthdiff && parnodesdiff;
    }

//迭代-标记par 和 深度
bool isCousins2(TreeNode* root, int x, int y) {
    bool res = false;
    if (!root) {
        return false;
    }
    
    TreeNode *xparNode = nullptr;
    TreeNode *yparNode = nullptr;
    queue<TreeNode *> myqueue;
    myqueue.push(root);
    int size = 1;
    int h = 0;
    int xh = -1;
    int yh = -1;
    while (myqueue.size()) {
        auto node= myqueue.front();
        myqueue.pop();
        size--;
        auto left = node->left;
        auto right = node->right;
        if (left) {
            myqueue.push(left);
            if (left->val == x) {
                xparNode = node;
                xh = h+1;
            }
            if (left->val == y) {
                yparNode = node;
                yh = h+1;
            }
        }
        if (right) {
            myqueue.push(right);
            if (right->val == x) {
                xparNode = node;
                xh = h+1;
            }
            if (right->val == y) {
                yparNode = node;
                yh = h+1;
            }
        }
        
        if (size == 0) {
            size = myqueue.size();
            h++;
        }
    }
    
    bool hdiff = (xh != -1)&& (xh==yh);
    bool pardiff = (xparNode != yparNode);
    
    return hdiff && pardiff;
    }


void _993_test()
{
    vector<int> list1 = {1,2,3,4};
    int flag1 = 4;
    int flag2 = 3;
    TreeNode *node1 = initTreeWithNULLVector(list1);
    
    bool res1 = isCousins1(node1,flag1,flag2);
    bool res2 = isCousins2(node1,flag1,flag2);
    
}
