//
//  894_所有可能的满二叉树.cpp
//  testC++++
//
//  Created by yekaihua on 2020/12/28.
//

#include "894_所有可能的满二叉树.hpp"
#include "common.h"

//满二叉树是一类二叉树，其中每个结点恰好有 0 或 2 个子结点。
//
//返回包含 N 个结点的所有可能满二叉树的列表。 答案的每个元素都是一个可能树的根结点。
//
//答案中每个树的每个结点都必须有 node.val=0。
//
//你可以按任何顺序返回树的最终列表。
//
//
//
//示例：
//
//输入：7
//输出：[[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
//解释：
//
//
//
//提示：
//
//1 <= N <= 20
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/all-possible-full-binary-trees
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

vector<TreeNode*> allPossibleFBT1(int N) {

    vector<TreeNode*> res = {};
    if (N <= 0) {
        return res;
    }
    
    auto leftN = N - 1;
    if (leftN <= 0) {
        res.push_back(new TreeNode(0));
        return res;
    }
    for (int i = 1; i<leftN; i+=2) {
        auto leftNum = i;
        auto rightNum = leftN-i;
        auto templeft = allPossibleFBT1(leftNum);
        auto tempright = allPossibleFBT1(rightNum);
        int sizeleft = templeft.size();
        int sizeright = tempright.size();
        for (int i = 0; i<sizeleft; i++) {
            for (int j = 0; j<sizeright; j++) {
                auto node = new TreeNode(0);
                node->left = templeft[i];
                node->right = tempright[j];
                res.push_back(node);
            }
        }
    }
    
    return res;
    }

vector<TreeNode*> allPossibleFBT2(int N) {

    vector<TreeNode*> res;
    return res;
    }

void _894_test()
{
    
    int flag1 = 7;
    
    
    vector<TreeNode*>  res1 = allPossibleFBT1(flag1);
    vector<TreeNode*>  res2 = allPossibleFBT2(flag1);
    
}
