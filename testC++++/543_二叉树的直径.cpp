//
//  543_二叉树的直径.cpp
//  testC++++
//
//  Created by yekaihua on 2020/12/26.
//

#import "543_二叉树的直径.hpp"
#import "common.h"

//给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。
//
//
//
//示例 :
//给定二叉树
//
//          1
//         / \
//        2   3
//       / \
//      4   5
//返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。
//
//
//
//注意：两结点之间的路径长度是以它们之间边的数目表示。
//
//通过次数85,026提交次数163,438
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/diameter-of-binary-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//迭代
//求深度
int diameterOfBinaryTree1highlength(TreeNode *root){
    int res = 0;
    if (!root) {
        return res;
    }
    auto left = diameterOfBinaryTree1highlength(root->left);
    auto right = diameterOfBinaryTree1highlength(root->right);
    //
    res = max(left, right)+1;
    return res;
}

int diameterOfBinaryTree1(TreeNode* root) {
    int res = 0;
    if (!root) {
        return res;
    }
    auto res1 = diameterOfBinaryTree1highlength(root->left);
    auto res2 = diameterOfBinaryTree1highlength(root->right);
    res = max(res1+res2,res);
    auto leftdia = diameterOfBinaryTree1(root->left);
    auto rightdia = diameterOfBinaryTree1(root->right);
    res = max(leftdia,res);
    res = max(rightdia,res);
    return res;
    }

//边的个数其实左子树个数 + 右子树高度
int diameterOfBinaryTree2maxed = 0;

int diameterOfBinaryTree1highlength2(TreeNode *root){
    int res = 0;
    if (!root) {
        return res;
    }
    
    auto left = diameterOfBinaryTree1highlength2(root->left);
    auto right = diameterOfBinaryTree1highlength2(root->right);
    diameterOfBinaryTree2maxed = max(diameterOfBinaryTree2maxed, left+right);
    return max(left, right)+1;
}

int diameterOfBinaryTree2(TreeNode* root) {

    diameterOfBinaryTree1highlength2(root);
    return diameterOfBinaryTree2maxed;
    }

void _543_test()
{
    vector<int> list1 = {1,2,3,4,5,NULL,6};
    TreeNode *node1 = initTreeWithNULLVector(list1);
    
    int res1 = diameterOfBinaryTree1(node1);
    int res2 = diameterOfBinaryTree2(node1);
    
}
