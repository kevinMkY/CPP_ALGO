//
//  110_平衡二叉树.cpp
//  testC++++
//
//  Created by yekaihua on 2020/12/26.
//

#import "110_平衡二叉树.hpp"
#import "common.h"

//给定一个二叉树，判断它是否是高度平衡的二叉树。
//
//本题中，一棵高度平衡二叉树定义为：
//
//一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
//
//
//
//示例 1：
//
//
//输入：root = [3,9,20,null,null,15,7]
//输出：true
//示例 2：
//
//
//输入：root = [1,2,2,3,3,null,null,4,4]
//输出：false
//示例 3：
//
//输入：root = []
//输出：true
//
//
//提示：
//
//树中的节点数在范围 [0, 5000] 内
//-104 <= Node.val <= 104
//通过次数159,913提交次数290,743
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/balanced-binary-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//递归---自上向下,height重复调用太多
int highlength(TreeNode *root){
    int h = 0;
    if (!root) {
        return h;
    }
    int lefthigh = highlength(root->left);
    int rightigh = highlength(root->right);
    return max(lefthigh, rightigh) + 1;
}

bool isBalanced1(TreeNode* root) {
    if (!root) {
        return true;
    }
    int leftres = highlength(root->left);
    int rightres = highlength(root->right);
    auto banlanceleft = isBalanced1(root->left);
    auto banlanceright = isBalanced1(root->right);
    auto res = abs(leftres-rightres) <=1;
    return res && banlanceleft && banlanceright;
    }


int highlength2(TreeNode *root){
    if (!root) {
        return 0;
    }
    auto leftres = highlength2(root->left);
    auto rightres = highlength2(root->right);
    if (leftres == -1 || rightres == -1 || abs(leftres - rightres) > 1) {
        return -1;
    }else{
        return max(leftres, rightres)+1;
    }
}
//迭代---自下向上,减少height重复调用
bool isBalanced2(TreeNode* root) {

    return highlength2(root) >=0;
    }

void _110_test()
{
    vector<int> list1 = {1,2,2,3,NULL,NULL,3,4,NULL,NULL,4};
    TreeNode *node1 = initTreeWithNULLVector(list1);
    
    bool res1 = isBalanced1(node1);
    bool res2 = isBalanced2(node1);
    
}
