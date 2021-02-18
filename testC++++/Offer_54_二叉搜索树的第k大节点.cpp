//
//  Offer_54_二叉搜索树的第k大节点.cpp
//  testC++++
//
//  Created by yekaihua on 2020/12/19.
//

#import "Offer_54_二叉搜索树的第k大节点.hpp"
#import "common.h"

//给定一棵二叉搜索树，请找出其中第k大的节点。
//
//
//
//示例 1:
//
//输入: root = [3,1,4,null,2], k = 1
//   3
//  / \
// 1   4
//  \
//   2
//输出: 4
//示例 2:
//
//输入: root = [5,3,6,2,4,null,null,1], k = 3
//       5
//      / \
//     3   6
//    / \
//   2   4
//  /
// 1
//输出: 4
//
//
//限制：
//
//1 ≤ k ≤ 二叉搜索树元素个数
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//中序遍历为升序..反转一下就是降序..第k大就是降序正数第k个
vector<int> centeroerder(TreeNode *root){
    vector<int> res;
    if (root == nullptr) {
        return res;
    }
    res.push_back(root->val);
    vector<int> leftOrder = centeroerder(root->left);
    vector<int> rightOrder = centeroerder(root->right);
    int leftsize = leftOrder.size();
    int rightsize = rightOrder.size();
    if (leftsize > 0) {
        res.insert(res.begin(), leftOrder.begin(),leftOrder.end());
    }
    if (rightsize > 0) {
        res.insert(res.end(), rightOrder.begin(),rightOrder.end());
    }
    return res;
}

//递归--
int kthLargest1(TreeNode* root, int k) {

    int res = 0;
    if (root == nullptr || k<1) {
        return res;
    }
    auto centerOrder = centeroerder(root);
    reverse(centerOrder.begin(), centerOrder.end());
    int size = centerOrder.size();
    if ((k-1) < size) {
        int val = centerOrder[k-1];
        return val;
    }
    return res;
   }

//迭代
int kthLargest2(TreeNode* root, int k) {

    int res;
    if (root == nullptr || k < 1) {
        return res;
    }
    
    vector<int> centerorder = {};
    stack<TreeNode *>mystack;
    while (root || !mystack.empty()) {
        while (root) {
            mystack.push(root);
            root=root->left;
        }
        root = mystack.top();
        mystack.pop();
        centerorder.push_back(root->val);
        root = root->right;
    }
    
    reverse(centerorder.begin(), centerorder.end());
    int size = centerorder.size();
    if ((k-1) < size) {
        int val = centerorder[k-1];
        return val;
    }
    return res;
   }

void _offer_54_test(){
    
    vector<int> list1 = {3,1,4,NULL,2};
    int flag1 = 1;
    TreeNode *node1 = initTreeWithNULLVector(list1);
    
    int res1 = kthLargest1(node1, flag1);
    int res2 = kthLargest2(node1, flag1);
    
}
