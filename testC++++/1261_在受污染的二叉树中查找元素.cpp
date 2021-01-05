//
//  1261_在受污染的二叉树中查找元素.cpp
//  testC++++
//
//  Created by yekaihua on 2020/12/30.
//

#include "1261_在受污染的二叉树中查找元素.hpp"
#include "common.h"


//给出一个满足下述规则的二叉树：
//
//root.val == 0
//如果 treeNode.val == x 且 treeNode.left != null，那么 treeNode.left.val == 2 * x + 1
//如果 treeNode.val == x 且 treeNode.right != null，那么 treeNode.right.val == 2 * x + 2
//现在这个二叉树受到「污染」，所有的 treeNode.val 都变成了 -1。
//
//请你先还原二叉树，然后实现 FindElements 类：
//
//FindElements(TreeNode* root) 用受污染的二叉树初始化对象，你需要先把它还原。
//bool find(int target) 判断目标值 target 是否存在于还原后的二叉树中并返回结果。
//
//
//示例 1：
//
//
//
//输入：
//["FindElements","find","find"]
//[[[-1,null,-1]],[1],[2]]
//输出：
//[null,false,true]
//解释：
//FindElements findElements = new FindElements([-1,null,-1]);
//findElements.find(1); // return False
//findElements.find(2); // return True
//示例 2：
//
//
//
//输入：
//["FindElements","find","find","find"]
//[[[-1,-1,-1,-1,-1]],[1],[3],[5]]
//输出：
//[null,true,true,false]
//解释：
//FindElements findElements = new FindElements([-1,-1,-1,-1,-1]);
//findElements.find(1); // return True
//findElements.find(3); // return True
//findElements.find(5); // return False
//示例 3：
//
//
//
//输入：
//["FindElements","find","find","find","find"]
//[[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]
//输出：
//[null,true,false,false,true]
//解释：
//FindElements findElements = new FindElements([-1,null,-1,-1,null,-1]);
//findElements.find(2); // return True
//findElements.find(3); // return False
//findElements.find(4); // return False
//findElements.find(5); // return True
//
//
//提示：
//
//TreeNode.val == -1
//二叉树的高度不超过 20
//节点的总数在 [1, 10^4] 之间
//调用 find() 的总次数在 [1, 10^4] 之间
//0 <= target <= 10^6
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/find-elements-in-a-contaminated-binary-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class FindElements1 {
public:
    FindElements1(TreeNode* root) {
        p = recoverTree(root);
    }
    
    TreeNode * recoverTree(TreeNode *root){
        if (!root) {
            return root;
        }
        queue<TreeNode *>myqueue;
        myqueue.push(root);
        root->val = 0;
        while (myqueue.size()) {
            auto node = myqueue.front();
            personnel[node->val] = node;
            myqueue.pop();
            auto left = node->left;
            auto right = node->right;
            if (left) {
                left->val = node->val * 2 + 1;
                myqueue.push(left);
            }
            if (right) {
                right->val = node->val * 2 + 2;
                myqueue.push(right);
            }
        }
        
        return root;
    }
    
    bool find(int target) {
        
        
        return personnel.count(target) > 0;
    }
    
    TreeNode*p;
    map<int,TreeNode*> personnel;
};

class FindElements2 {
public:
    FindElements2(TreeNode* root) {
        p=recoverTree(root);
    }
    
    TreeNode * recoverTree(TreeNode *root){
        if (!root) {
            return root;
        }
        queue<TreeNode *>myqueue;
        myqueue.push(root);
        root->val = 0;
        while (myqueue.size()) {
            auto node = myqueue.front();
            myqueue.pop();
            auto left = node->left;
            auto right = node->right;
            if (left) {
                left->val = node->val * 2 + 1;
                myqueue.push(left);
            }
            if (right) {
                right->val = node->val * 2 + 2;
                myqueue.push(right);
            }
        }
        return root;
    }
    bool find(int target) {
        auto x = target+1;
        TreeNode *temp = p;
        int count = __builtin_clz(x);
        int initval = 1 << (30 - count);
        for(int bit = initval; bit != 0 && p != nullptr; bit >>= 1)
        {
            if ((bit & x) == 0) {
                temp = temp->left;
            }else{
                temp = temp->right;
            }
        }
        
        return temp != nullptr;
    }
    
    TreeNode*p;
    map<int,TreeNode*> personnel;
};

void _1261_test()
{
    vector<int> list1 = {-1, NULL,-1};
    int flag1 = 1;
    int flag2 = 2;
    TreeNode *node1 = initTreeWithNULLVector(list1);
    
    FindElements2* obj = new FindElements2(node1);
    bool param_1 = obj->find(flag1);
    bool param_2 = obj->find(flag2);
    
}
