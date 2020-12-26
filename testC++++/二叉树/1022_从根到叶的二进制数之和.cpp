//
//  1022_从根到叶的二进制数之和.cpp
//  testC++++
//
//  Created by yekaihua on 2020/12/21.
//

#import "1022_从根到叶的二进制数之和.hpp"
#import "common.h"

//给出一棵二叉树，其上每个结点的值都是 0 或 1 。每一条从根到叶的路径都代表一个从最高有效位开始的二进制数。例如，如果路径为 0 -> 1 -> 1 -> 0 -> 1，那么它表示二进制数 01101，也就是 13 。
//
//对树上的每一片叶子，我们都要找出从根到该叶子的路径所表示的数字。
//
//返回这些数字之和。题目数据保证答案是一个 32 位 整数。
//
//
//
//示例 1：
//
//
//输入：root = [1,0,1,0,1,0,1]
//输出：22
//解释：(100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
//示例 2：
//
//输入：root = [0]
//输出：0
//示例 3：
//
//输入：root = [1]
//输出：1
//示例 4：
//
//输入：root = [1,1]
//输出：3
//
//
//提示：
//
//树中的结点数介于 1 和 1000 之间。
//Node.val 为 0 或 1 。
//通过次数13,191提交次数19,416
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/sum-of-root-to-leaf-binary-numbers
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//递归
vector<vector<int>> sumNode(TreeNode* root) {
    vector<vector<int>> res = {};
    if (!root) {
        return res;
    }
    int val = root->val;
    auto left = root->left;
    auto right = root->right;
    vector<vector<int>> leftres = {},rightres = {};
    if (left) {
        leftres = sumNode(left);
    }
    if (right) {
        rightres = sumNode(right);
    }
    auto leftsize = leftres.size();
    auto rightsize = rightres.size();
    auto maxsize = max(leftsize, rightsize);
    if (maxsize > 0) {
        for (int i = 0; i<leftsize; i++) {
            vector<int> leftval = leftres[i];
            leftval.insert(leftval.begin(), val);
            res.push_back(leftval);
        }
        for (int i = 0; i<rightsize; i++) {
            vector<int> rightval = rightres[i];
            rightval.insert(rightval.begin(), val);
            res.push_back(rightval);
        }
    
    }else{
        res.push_back({val});
    }
    
    return res;
    }

int sumRootToLeaf1(TreeNode* root) {
    vector<vector<int>> res = sumNode(root);
    int ressize =res.size();
    int sum = 0;
    for (int i = 0; i<ressize; i++) {
        vector<int> valres = res[i];
        int tempsum = 0;
        int valsize = valres.size();
        for (int j = valsize - 1; j >= 0; j--) {
            int resval = valres[j];
            tempsum += (resval * pow(2, valsize-j-1));
        }
        sum += tempsum;
    }
    return sum;
    }

//迭代
int sumRootToLeaf2(TreeNode* root) {
    int sum = 0;
    return sum;
    }

void _1022_test()
{
    vector<int> list1 = {1,0,1,0,1,0,1};
    int flag1 = 0;
    TreeNode *node1 = initTreeWithNULLVector(list1);
    
    int res1 = sumRootToLeaf1(node1);
    int res2 = sumRootToLeaf2(node1);
    
}
