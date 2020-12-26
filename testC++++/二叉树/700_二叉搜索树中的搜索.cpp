//
//  700_二叉搜索树中的搜索.cpp
//  testC++++
//
//  Created by yekaihua on 2020/12/19.
//

#import "700_二叉搜索树中的搜索.hpp"
#import "common.h"

//给定二叉搜索树（BST）的根节点和一个值。 你需要在BST中找到节点值等于给定值的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 NULL。
//
//例如，
//
//给定二叉搜索树:
//
//        4
//       / \
//      2   7
//     / \
//    1   3
//
//和值: 2
//你应该返回如下子树:
//
//      2
//     / \
//    1   3
//在上述示例中，如果要找的值是 5，但因为没有节点值为 5，我们应该返回 NULL。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/search-in-a-binary-search-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

TreeNode* searchBST1(TreeNode* root, int val) {
    if (root == nullptr) {
        return root;
    }
    
    int curval = root->val;
    if (curval == val) {
        return root;
    }else if (curval > val){
        return searchBST1(root->left, val);
    }else{
        return searchBST1(root->right, val);
    }
    }

TreeNode* searchBST2(TreeNode* root, int val) {
    if (root == nullptr) {
        return root;
    }
    queue<TreeNode *>myqueue;
    myqueue.push(root);
    while (!myqueue.empty()) {
        auto node = myqueue.front();
        auto nodeleft = node->left;
        auto noderight = node->right;
        myqueue.pop();
        int nodeval = node->val;

        if (nodeval == val) {
            return node;
        }else if(nodeval > val && nodeleft){
            myqueue.push(nodeleft);
        }else if(nodeval < val && noderight){
            myqueue.push(noderight);
        }
    }
    return nullptr;
    }

void _700_test()
{
    vector<int> list1 = {4,2,7,1,3};
    int search1 = 2;
    TreeNode *node1 = initTreeWithNULLVector(list1);
    
    TreeNode* res1 = searchBST1(node1,search1);
    TreeNode* res2 = searchBST2(node1,search1);
    
}
