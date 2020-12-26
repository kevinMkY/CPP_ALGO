//
//  100_相同的树.cpp
//  testC++++
//
//  Created by yekaihua on 2020/12/23.
//

#import "100_相同的树.hpp"
#import "common.h"

//给定两个二叉树，编写一个函数来检验它们是否相同。
//
//如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
//
//示例 1:
//
//输入:       1         1
//          / \       / \
//         2   3     2   3
//
//        [1,2,3],   [1,2,3]
//
//输出: true
//示例 2:
//
//输入:      1          1
//          /           \
//         2             2
//
//        [1,2],     [1,null,2]
//
//输出: false
//示例 3:
//
//输入:       1         1
//          / \       / \
//         2   1     1   2
//
//        [1,2,1],   [1,1,2]
//
//输出: false
//通过次数163,034提交次数270,940
//在真实的面试中遇到过这道题？
//
//是
//
//否
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/same-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//递归
bool isSameTree1(TreeNode* p, TreeNode* q) {

    if (!p && !q) {
        return true;
    }else if (!p || !q) {
        return false;
    }
    
    bool leftres = isSameTree1(p->left, q->left);
    bool rightres = isSameTree1(p->right, q->right);
    auto val1 = p->val;
    auto val2 = q->val;
    
    
    return leftres && rightres && (val1 == val2);
    
    }

//迭代
bool isSameTree2(TreeNode* p, TreeNode* q) {
    if (!p && !q) {
        return true;
    }
    if (!p || !q) {
        return false;
    }
    
    queue<TreeNode *>myqueue1;
    queue<TreeNode *>myqueue2;
    myqueue1.push(p);
    myqueue2.push(q);
    while (!myqueue1.empty() && !myqueue2.empty()) {
        auto node1 = myqueue1.front();
        myqueue1.pop();
        auto node2 = myqueue2.front();
        myqueue2.pop();
        if (node1->val != node2->val) {
            return false;
        }
        auto left1 = node1->left;
        auto left2 = node2->left;
        auto right1 = node1->right;
        auto right2 = node2->right;
        if (left1 && left2 == nullptr) {
            return false;
        }else if (left1 == nullptr && left2) {
            return false;
        }else if (left1 == nullptr && left2 == nullptr) {
            
        }else if (left1->val != left2->val){
            return false;
        }else{
            myqueue1.push(left1);
            myqueue2.push(left2);
        }
        if (right1 && right2 == nullptr) {
            return false;
        }else if (right1 == nullptr && right2) {
            return false;
        }else if (right1 == nullptr && right2 == nullptr) {
            
        }else if (right1->val != right2->val){
            return false;
        }else{
            myqueue1.push(right1);
            myqueue2.push(right2);
        }
        if (myqueue1.size() != myqueue2.size()) {
            return false;
        }
    }
    
    return true;
    }

void _100_test()
{
    vector<int> list1 = {1};
    vector<int> list2 = {1,NULL,2};
    vector<int> list3 = {1,2,3};
    vector<int> list4 = {1,2,3};
    
    TreeNode *node1 = initTreeWithNULLVector(list1);
    TreeNode *node2 = initTreeWithNULLVector(list2);
    TreeNode *node3 = initTreeWithNULLVector(list3);
    TreeNode *node4 = initTreeWithNULLVector(list4);
    
    bool res1 = isSameTree1(node1,node2);
    bool res2 = isSameTree2(node3,node4);
    
}
