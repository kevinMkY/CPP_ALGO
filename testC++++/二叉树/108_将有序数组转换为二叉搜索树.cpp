//
//  108_将有序数组转换为二叉搜索树.cpp
//  testC++++
//
//  Created by yekaihua on 2020/12/19.
//

#import "108_将有序数组转换为二叉搜索树.hpp"
#import "common.h"

//将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
//
//本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
//
//示例:
//
//给定有序数组: [-10,-3,0,5,9],
//
//一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：
//
//      0
//     / \
//   -3   9
//   /   /
// -10  5
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//递归 -- 中序就是升序
TreeNode* sortedArrayToBST1(vector<int>& nums) {

    TreeNode*res = nullptr;
    int size = nums.size();
    if (size == 0) {
        return res;
    }
    int centerindex = (size)/2;
    
    vector<int> leftnums,rightnums;
    for (int i =0;i<size; i++) {
        int val = nums[i];
        if (i < centerindex) {
            leftnums.push_back(val);
        }else if(i == centerindex){
            res = new TreeNode(val);
        }else{
            rightnums.push_back(val);
        }
    }
    
    if (res) {
        res->left = sortedArrayToBST1(leftnums);
        res->right = sortedArrayToBST1(rightnums);
    }
    return res;
    }


void _108_test()
{
    vector<int> list1 = {-10,-3,0,5,9};
    
    TreeNode *res1 = sortedArrayToBST1(list1);

    
}
