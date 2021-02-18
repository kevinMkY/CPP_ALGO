//
//  235_二叉搜索树的最近公共祖先.cpp
//  testC++++
//
//  Created by yekaihua on 2020/12/22.
//

#import "235_二叉搜索树的最近公共祖先.hpp"
#import "common.h"

//给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
//
//百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
//
//例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]
//
//
//
//
//
//示例 1:
//
//输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
//输出: 6
//解释: 节点 2 和节点 8 的最近公共祖先是 6。
//示例 2:
//
//输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
//输出: 2
//解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。
//
//
//说明:
//
//所有节点的值都是唯一的。
//p、q 为不同节点且均存在于给定的二叉搜索树中。
//通过次数114,456提交次数173,694
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//递归
TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {

    TreeNode*  res = nullptr;
    if (!root) {
        return res;
    }
    auto leftgg = lowestCommonAncestor1(root->left, p, q);
    auto rightgg = lowestCommonAncestor1(root->right, p, q);
    if (root->val == q->val || root->val == p->val) {
        return root;
    }else if(leftgg && rightgg){
        return root;
    }else if (leftgg){
        return leftgg;
    }else if (rightgg){
        return rightgg;
    }else{
        return res;
    }
    }

//迭代
TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {

    TreeNode* res = nullptr;
    if (!root) {
        return res;
    }
    auto pval = p->val;
    auto qval = q->val;
    auto lowval = min(pval, qval);
    auto highval = max(pval, qval);
    queue<TreeNode *>myqueue;
    myqueue.push(root);
    while (!myqueue.empty()) {
        auto node = myqueue.front();
        myqueue.pop();
        auto val = node->val;
        auto left = node->left;
        auto right = node->right;
        if (lowval<=val && val<= highval) {
            return node;
        }else if(val>highval && left){
            myqueue.push(left);
        }else if(val<lowval && right){
            myqueue.push(right);
        }else{
            return res;
        }
    }
    
    return res;
    }

void _235_test()
{
    vector<int> list1 = {6,2,8,0,4,7,9,NULL,NULL,3,5};
    int flag1 = 2;
    int flag2 = 8;
    vector<int> list2 = {2,1};
    int flag3 = 2;
    int flag4 = 1;
    TreeNode *node1 = initTreeWithNULLVector(list1);
    TreeNode *p = new TreeNode(flag1);
    TreeNode *q = new TreeNode(flag2);
    
    TreeNode *node2 = initTreeWithNULLVector(list2);
    TreeNode *p2 = new TreeNode(flag1);
    TreeNode *q2 = new TreeNode(flag2);
    
    TreeNode* res1 = lowestCommonAncestor1(node1,p,q);
    TreeNode* res2 = lowestCommonAncestor2(node2,p2,q2);
    
    
}
