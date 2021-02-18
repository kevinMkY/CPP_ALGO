//
//  530_二叉搜索树的最小绝对差.cpp
//  testC++++
//
//  Created by yekaihua on 2020/12/23.
//

#import "530_二叉搜索树的最小绝对差.hpp"
#import "common.h"
//
//给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。
//
//
//
//示例：
//
//输入：
//
//   1
//    \
//     3
//    /
//   2
//
//输出：
//1
//
//解释：
//最小绝对差为 1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。
//
//
//提示：
//
//树中至少有 2 个节点。
//本题与 783 https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/ 相同
//通过次数52,816提交次数
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//中序
vector<int> calculateDiff(TreeNode *root){
    vector<int>res;
    if (!root) {
        return res;
    }
    
    auto left = root->left;
    auto right = root->right;
    auto leftres = calculateDiff(left);
    auto rightres = calculateDiff(right);
    res.insert(res.end(), leftres.begin(),leftres.end());
    res.push_back(root->val);
    res.insert(res.end(), rightres.begin(),rightres.end());
    
    return res;
}

//递归
int getMinimumDifference1(TreeNode* root) {
    if (!root) {
        return 0;
    }
    vector<int> res = calculateDiff(root);
    int minnum = -1;
    auto size = res.size();
    for (int i =0;i<size; i++) {
        auto firstval = res[i];
        for (int j =i+1;j<size; j++) {
            auto secval = res[j];
            auto curmin = abs(firstval-secval);
            if (minnum == -1) {
                minnum = curmin;
            }else{
                minnum = min(minnum,curmin);
            }
            
        }
    }
    return minnum;
    }

//迭代
int getMinimumDifference2(TreeNode* root) {
    int res = INT_MAX;
    if (!root) {
        return 0;
    }
    
    stack<TreeNode *>mystack;
    TreeNode *pre = nullptr;
    while (root || mystack.size()) {
        while (root) {
            mystack.push(root);
            root = root->left;
        }
        root = mystack.top();
        mystack.pop();
        if (pre) {
            res = min(res, abs(pre->val - root->val));
        }
        pre=root;
        root = root->right;
        
    }
    
    return res;
    }

void _530_test()
{
    vector<int> list1 = {1,NULL,5,3};
    vector<int> list2 = {543,384,652,NULL,445,NULL,699};
    

    TreeNode *node1 = initTreeWithNULLVector(list1);
    TreeNode *node2 = initTreeWithNULLVector(list2);
    int res1 = getMinimumDifference1(node1);
    int res2 = getMinimumDifference1(node2);
    int res3 = getMinimumDifference2(node1);
    int res4 = getMinimumDifference2(node2);
    
}
