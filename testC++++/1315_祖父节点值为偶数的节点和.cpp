//
//  1315_祖父节点值为偶数的节点和.cpp
//  testC++++
//
//  Created by yekaihua on 2020/12/28.
//

#include "1315_祖父节点值为偶数的节点和.hpp"
#include "common.h"

//给你一棵二叉树，请你返回满足以下条件的所有节点的值之和：
//
//该节点的祖父节点的值为偶数。（一个节点的祖父节点是指该节点的父节点的父节点。）
//如果不存在祖父节点值为偶数的节点，那么返回 0 。
//
// 
//
//示例：
//
//
//
//输入：root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
//输出：18
//解释：图中红色节点的祖父节点的值为偶数，蓝色节点为这些红色节点的祖父节点。
// 
//
//提示：
//
//树中节点的数目在 1 到 10^4 之间。
//每个节点的值在 1 到 100 之间。
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/sum-of-nodes-with-even-valued-grandparent
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

int sumEvenGrandparent1(TreeNode* root) {

    int res = 0;
    if (!root) {
        return res;
    }
    bool allow = root->val%2==0;
    auto left = root->left;
    auto right = root->right;
    if (left) {
        res+=sumEvenGrandparent1(left);
        if (allow) {
            auto leftleft = left->left;
            auto leftright = left->right;
            if (leftleft) {
                res+=leftleft->val;
            }
            if (leftright) {
                res+=leftright->val;
            }
        }
    }
    if (right) {
        res+=sumEvenGrandparent1(right);
        if (allow) {
            auto rightleft = right->left;
            auto rightright = right->right;
            if (rightleft) {
                res+=rightleft->val;
            }
            if (rightright) {
                res+=rightright->val;
            }
        }
    }
    return res;
    }

int sumEvenGrandparent2(TreeNode* root) {

    int res = 0;
    if (!root) {
        return res;
    }
    queue<TreeNode *>myqueue;
    myqueue.push(root);
    while (myqueue.size()) {
        auto node = myqueue.front();
        myqueue.pop();
        auto left = node->left;
        auto right = node->right;
        bool allow = node->val%2==0;    //偶数
        if (left) {
            myqueue.push(left);
            if (allow) {
                auto leftleft = left->left;
                auto leftright = left->right;
                if (leftleft) {
                    res+=leftleft->val;
                }
                if (leftright) {
                    res+=leftright->val;
                }
            }
        }
        if (right) {
            myqueue.push(right);
            if (allow) {
                auto rightleft = right->left;
                auto rightright = right->right;
                if (rightleft) {
                    res+=rightleft->val;
                }
                if (rightright) {
                    res+=rightright->val;
                }
            }
        }
    }
    return res;
    }

void _1315_test()
{
    vector<int> list1 = {6,7,8,2,7,1,3,9,NULL,1,4,NULL,NULL,NULL,5};
    
    TreeNode *node1 = initTreeWithNULLVector(list1);
    
    int res1 = sumEvenGrandparent1(node1);
    int res2 = sumEvenGrandparent2(node1);
    
}
