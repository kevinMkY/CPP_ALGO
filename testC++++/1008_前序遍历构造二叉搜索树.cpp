//
//  1008_前序遍历构造二叉搜索树.cpp
//  testC++++
//
//  Created by yekaihua on 2021/1/4.
//

#include "1008_前序遍历构造二叉搜索树.hpp"
#include "common.h"

//返回与给定前序遍历 preorder 相匹配的二叉搜索树（binary search tree）的根结点。
//
//(回想一下，二叉搜索树是二叉树的一种，其每个节点都满足以下规则，对于 node.left 的任何后代，值总 < node.val，而 node.right 的任何后代，值总 > node.val。此外，前序遍历首先显示节点 node 的值，然后遍历 node.left，接着遍历 node.right。）
//
//题目保证，对于给定的测试用例，总能找到满足要求的二叉搜索树。
//
//
//
//示例：
//
//输入：[8,5,1,7,10,12]
//输出：[8,5,10,1,7,null,12]
//
//
//
//提示：
//
//1 <= preorder.length <= 100
//1 <= preorder[i] <= 10^8
//preorder 中的值互不相同
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/construct-binary-search-tree-from-preorder-traversal
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//递归
TreeNode* bstFromPreorder1(vector<int>& preorder) {
    TreeNode* res = nullptr;
    auto size = preorder.size();
    if (size < 1) {
        return res;
    }
    
    auto val = preorder.front();
    vector<int> leftRes = {}, rightRes= {};
    for (int i = 1; i<size; i++) {
        auto nextval = preorder[i];
        if (val < nextval) {
            rightRes.push_back(nextval);
        }else{
            leftRes.push_back(nextval);
        }
    }
    res = new TreeNode(val);
    res->left = bstFromPreorder1(leftRes);
    res->right = bstFromPreorder1(rightRes);
    return res;
    }

//迭代
TreeNode* bstFromPreorder2(vector<int>& preorder) {
    TreeNode* res = nullptr;
    auto size = preorder.size();
    if (size < 1) {
        return res;
    }
    res = new TreeNode(preorder.front());
    for (int i = 1; i < size; i++) {
        auto nextval = preorder[i];
        auto node = new TreeNode(nextval);
        auto temp = res;
        while (temp) {
            auto left = temp->left;
            auto right = temp->right;
            auto curval = temp->val;
            if (nextval < curval) {
                if (left) {
                    temp = left;
                }else{
                    temp->left = node;
                    break;
                }
            }else if (nextval > curval){
                if (right) {
                    temp = right;
                }else{
                    temp->right =node;
                    break;
                }
            }
        }
    }
    
    return res;
    }


//前序 + 中序 可以构建二叉树
TreeNode*bstFromPreorder3Node (vector<int>& preorder,vector<int>& inorder,
                               int preleft,int preright,
                               int inleft,int inright){
    TreeNode*res = nullptr;
    auto size1 = preorder.size();
    auto size2 = inorder.size();
    if (size1 != size2 || preleft > preright || inleft > inright || preright >= size1 || inright >= size2) {
        return res;
    }
    
    //[         8,     5,1,7,      10,12]
    //[1,5,7,   8,                 10,12]
    
    int premidindex = preleft;
    int premidval = preorder[premidindex];
    int inmidindex = -1;
    for (int i = 0; i<size2; i++) {
        auto inval = inorder[i];
        if (premidval == inval) {
            inmidindex = i;
        }
    }
    int leftsize = inmidindex - inleft;
    int rightsize = inright - inmidindex;
    
    int leftpreleft = premidindex+1;
    int leftpreright = premidindex+1 + (leftsize-1);
    int rightpreleft = preright-(rightsize-1);
    int rightpreright = preright;
    
    int leftinleft = inleft;
    int leftinright = inmidindex-1;
    int rightinleft = inmidindex+1;
    int rightinright = inright;
    res = new TreeNode(premidval);
    res->left = bstFromPreorder3Node(preorder, inorder, leftpreleft, leftpreright, leftinleft, leftinright);
    res->right = bstFromPreorder3Node(preorder, inorder, rightpreleft, rightpreright, rightinleft, rightinright);
    return res;
}

//先序遍历排序得到中序遍历
TreeNode* bstFromPreorder3(vector<int>& preorder) {
    TreeNode* res = nullptr;
    auto size = preorder.size();
    if (size < 1) {
        return res;
    }
    vector<int> inorder{preorder.begin(),preorder.end()};
    sort(inorder.begin(),inorder.end());
    res = bstFromPreorder3Node(preorder, inorder,0,preorder.size()-1,0,inorder.size()-1);
    return res;
}
void _1008_test()
{
    vector<int> list1 = {8,5,1,7,10,12};
    vector<int> list2 = {4,2};
//    TreeNode* res1 = bstFromPreorder1(list1);
//    TreeNode* res2 = bstFromPreorder1(list2);
//    TreeNode* res3 = bstFromPreorder2(list1);
//    TreeNode* res4 = bstFromPreorder2(list2);
    TreeNode* res5 = bstFromPreorder3(list1);
    
}
