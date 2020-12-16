//
//  145_二叉树的后序遍历.cpp
//  testC++++
//
//  Created by ykh on 2020/9/22.
//

#include "145_二叉树的后序遍历.hpp"
#include "common.h"

//给定一个二叉树，返回它的 后序 遍历。
//
//示例:
//
//输入: [1,null,2,3]
//   1
//    \
//     2
//    /
//   3
//
//输出: [3,2,1]
//进阶: 递归算法很简单，你可以通过迭代算法完成吗？
//
//通过次数122,705提交次数169,408
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//迭代
//方法1
//------------------这种递归是将前序修改-------
//前序-->中左右-->将左右入栈交换下顺序-->中右左-->颠倒一下-->左右中

//方法2
//这道题的难点在于仅利用栈去判断该节点是否为父结点，创新性思路是每次在栈中压入父节点后压入nullptr，之后再依次压入右子节点和左子节点。


//递归
vector<int> postorderTraversal1(TreeNode* root) {

    vector<int> res;
    if (root == nullptr) {
        return res;
    }
    vector<int> resleft = postorderTraversal1(root->left);
    vector<int> resright = postorderTraversal1(root->right);
    res.insert(res.end(), resleft.begin(),resleft.end());
    res.insert(res.end(), resright.begin(),resright.end());
    res.push_back(root->val);
    return res;
    }


//迭代

vector<int> postorderTraversal2(TreeNode* root) {

    vector<int> res;
    
    return res;
            
}

//后序-->左右中
//前序是中左右
vector<int> postorderTraversal3(TreeNode* root) {
    
    vector<int> res;
    if (root == nullptr) {
        return res;
    }
    
    stack<TreeNode *>mystack;
    mystack.push(root);
    while (!mystack.empty()) {
        TreeNode *node = mystack.top();
        mystack.pop();
        res.push_back(node->val);
        if (node->left) {
            mystack.push(node->left);
        }
        if (node->right) {
            mystack.push(node->right);
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

void _145_test(){
    
    
    vector<int> list1 = {4,2,7,1,3,6,9};
    vector<int> list2 = {1,NULL,2,3};
    TreeNode *node1 = initTreeWithVector(list1);
    TreeNode *node2 = initTreeWithVector(list2);

    
    vector<int> res1 = postorderTraversal1(node1);
    vector<int> res2 = postorderTraversal1(node2);
    vector<int> res3 = postorderTraversal2(node1);
    vector<int> res4 = postorderTraversal2(node2);
    vector<int> res5 = postorderTraversal3(node1);
    vector<int> res6 = postorderTraversal3(node2);

    
}
