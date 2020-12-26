//
//  872_叶子相似的树.cpp
//  testC++++
//
//  Created by yekaihua on 2020/12/22.
//

#import "872_叶子相似的树.hpp"
#import "common.h"

//请考虑一棵二叉树上所有的叶子，这些叶子的值按从左到右的顺序排列形成一个 叶值序列 。
//
//
//
//举个例子，如上图所示，给定一棵叶值序列为 (6, 7, 4, 9, 8) 的树。
//
//如果有两棵二叉树的叶值序列是相同，那么我们就认为它们是 叶相似 的。
//
//如果给定的两个头结点分别为 root1 和 root2 的树是叶相似的，则返回 true；否则返回 false 。
//
//
//
//示例 1：
//
//
//
//输入：root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
//输出：true
//示例 2：
//
//输入：root1 = [1], root2 = [1]
//输出：true
//示例 3：
//
//输入：root1 = [1], root2 = [2]
//输出：false
//示例 4：
//
//输入：root1 = [1,2], root2 = [2,2]
//输出：true
//示例 5：
//
//
//
//输入：root1 = [1,2,3], root2 = [1,3,2]
//输出：false
//
//
//提示：
//
//给定的两棵树可能会有 1 到 200 个结点。
//给定的两棵树上的值介于 0 到 200 之间。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/leaf-similar-trees
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//递归
vector<int> leafVector(TreeNode* root) {
    vector<int> res = {};
    if (!root) {
        return res;
    }
    auto left = root->left;
    auto right = root->right;
    if (left || right) {
        auto leftres = leafVector(left);
        auto rightres = leafVector(right);
        res.insert(res.end(), leftres.begin(),leftres.end());
        res.insert(res.end(), rightres.begin(),rightres.end());
    }else{
        res.push_back(root->val);
    }
    return res;
}

bool leafSimilar1(TreeNode* root1, TreeNode* root2) {
    vector<int> leaf1 = leafVector(root1);
    vector<int> leaf2 = leafVector(root2);
    
    return leaf1 == leaf2;
    }


vector<int> leafVector2(TreeNode* root) {
    vector<int> res = {};
    if (!root) {
        return res;
    }
    stack<TreeNode *>mystack;
    while (root || !mystack.empty()) {
        while (root) {
            mystack.push(root);
            root = root->left;
        }
        root = mystack.top();
        mystack.pop();
        if (!root->left && !root->right) {
            res.push_back(root->val);
        }
        root = root->right;
    }
    return res;
}

//迭代
bool leafSimilar2(TreeNode* root1, TreeNode* root2) {
    vector<int> leaf1 = leafVector2(root1);
    vector<int> leaf2 = leafVector2(root2);
    
    return leaf1 == leaf2;
    }

void _872_test()
{
    vector<int> list1 = {3,5,1,6,2,9,8,NULL,NULL,7,4};
    vector<int> list2 = {3,5,1,6,7,4,2,NULL,NULL,NULL,NULL,NULL,NULL,9,8};
    vector<int> list3 = {1,2,NULL,3};
    vector<int> list4 = {1,3};

    TreeNode *node1 = initTreeWithNULLVector(list1);
    TreeNode *node2 = initTreeWithNULLVector(list2);
    TreeNode *node3 = initTreeWithNULLVector(list3);
    TreeNode *node4 = initTreeWithNULLVector(list4);
    
//    bool res1 = leafSimilar1(node1,node2);
    bool res2 = leafSimilar2(node3,node4);
    
    
}
