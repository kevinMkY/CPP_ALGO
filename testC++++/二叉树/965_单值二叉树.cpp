//
//  965_单值二叉树.cpp
//  testC++++
//
//  Created by yekaihua on 2020/12/21.
//

#import "965_单值二叉树.hpp"
#import "common.h"

//如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。
//
//只有给定的树是单值二叉树时，才返回 true；否则返回 false。
//
//
//
//示例 1：
//
//
//
//输入：[1,1,1,1,1,null,1]
//输出：true
//示例 2：
//
//
//
//输入：[2,2,2,5,2]
//输出：false
//
//
//提示：
//
//给定树的节点数范围是 [1, 100]。
//每个节点的值都是整数，范围为 [0, 99] 。
//通过次数23,024提交次数33,612
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/univalued-binary-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//递归
bool isUnivalTreetest(TreeNode* root,int val) {
    bool res = false;
    if (!root) {
        return res;
    }
    
    auto curval = root->val;
    auto left = root->left;
    auto right = root->right;
    if (curval != val) {
        return res;
    }
    auto leftres = true,rightres= true;
    if (left) {
        leftres = isUnivalTreetest(left, val);
    }
    if (right) {
        rightres = isUnivalTreetest(right, val);
    }
    
    return !res && leftres && rightres;
    }

bool isUnivalTree1(TreeNode* root) {
    
    return isUnivalTreetest(root,root->val);
    }


//迭代
bool isUnivalTree2(TreeNode* root) {
    bool res = false;
    if (!root) {
        return res;
    }
    queue<TreeNode *>myqueue;
    myqueue.push(root);
    int val = root->val;
    while (!myqueue.empty()) {
        auto node = myqueue.front();
        myqueue.pop();
        auto left = node->left;
        auto right = node->right;
        if (node->val != val) {
            return false;
        }
        if (left) {
            myqueue.push(left);
        }
        if (right) {
            myqueue.push(right);
        }
    }
    return !res;
    }

void _965_test()
{
    vector<int> list1 = {1,1,1,1,1,NULL,1};
    vector<int> list2 = {2,2,2,5,2};
    int flag1 = 0;
    TreeNode *node1 = initTreeWithNULLVector(list1);
    TreeNode *node2 = initTreeWithNULLVector(list2);
    
    bool res1 = isUnivalTree1(node1);
    bool res2 = isUnivalTree2(node1);
    bool res3 = isUnivalTree1(node2);
    bool res4 = isUnivalTree2(node2);
    
}
