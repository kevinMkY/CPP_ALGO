//
//  654_最大二叉树.cpp
//  testC++++
//
//  Created by yekaihua on 2020/12/28.
//

#include "654_最大二叉树.hpp"
#include "common.h"

//给定一个不含重复元素的整数数组。一个以此数组构建的最大二叉树定义如下：
//
//二叉树的根是数组中的最大元素。
//左子树是通过数组中最大值左边部分构造出的最大二叉树。
//右子树是通过数组中最大值右边部分构造出的最大二叉树。
//通过给定的数组构建最大二叉树，并且输出这个树的根节点。
//
//
//
//示例 ：
//
//输入：[3,2,1,6,0,5]
//输出：返回下面这棵树的根节点：
//
//      6
//    /   \
//   3     5
//    \    /
//     2  0
//       \
//        1
//
//
//提示：
//
//给定的数组的大小在 [1, 1000] 之间。
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/maximum-binary-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//递归
TreeNode* constructMaximumBinaryTree1(vector<int>& nums) {
    TreeNode*res = nullptr;
    auto size = nums.size();
    if (size == 0) {
        return res;
    }
    int maxindex = 0;
    for (int i = 0; i<size; i++) {
        auto val = nums[i];
        if (val > nums[maxindex]) {
            maxindex = i;
        }
    }
    
    res = new TreeNode(nums[maxindex]);
    vector<int> leftnums = {};
    leftnums.insert(leftnums.begin(), nums.begin(),nums.begin()+maxindex);
    vector<int> rightnums = {};
    rightnums.insert(rightnums.begin(), nums.begin()+maxindex+1,nums.end());
    res->left = constructMaximumBinaryTree1(leftnums);
    res->right = constructMaximumBinaryTree1(rightnums);
    
    return res;
    }

//迭代
TreeNode* constructMaximumBinaryTree2(vector<int>& nums) {
    TreeNode*res = nullptr;
    return res;
    }

void _654_test()
{
    vector<int> list1 = {3,2,1,6,0,5};
    
    TreeNode* res1 = constructMaximumBinaryTree1(list1);
    TreeNode* res2 = constructMaximumBinaryTree2(list1);
    
}
