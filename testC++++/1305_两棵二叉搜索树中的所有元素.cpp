//
//  1305_两棵二叉搜索树中的所有元素.cpp
//  testC++++
//
//  Created by yekaihua on 2020/12/30.
//

#include "1305_两棵二叉搜索树中的所有元素.hpp"
#include "common.h"

//给你 root1 和 root2 这两棵二叉搜索树。
//
//请你返回一个列表，其中包含 两棵树 中的所有整数并按 升序 排序。.
//
//
//
//示例 1：
//
//
//
//输入：root1 = [2,1,4], root2 = [1,0,3]
//输出：[0,1,1,2,3,4]
//示例 2：
//
//输入：root1 = [0,-10,10], root2 = [5,1,7,0,2]
//输出：[-10,0,0,1,2,5,7,10]
//示例 3：
//
//输入：root1 = [], root2 = [5,1,7,0,2]
//输出：[0,1,2,5,7]
//示例 4：
//
//输入：root1 = [0,-10,10], root2 = []
//输出：[-10,0,10]
//示例 5：
//
//
//
//输入：root1 = [1,null,8], root2 = [8,1]
//输出：[1,1,8,8]
//
//
//提示：
//
//每棵树最多有 5000 个节点。
//每个节点的值在 [-10^5, 10^5] 之间。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/all-elements-in-two-binary-search-trees
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

void getAllElements1dfs(TreeNode *root,vector<int> &nums){
    if (!root) {
        return;
    }
    getAllElements1dfs(root->left, nums);
    nums.push_back(root->val);
    getAllElements1dfs(root->right, nums);
}

vector<int> getAllElements1(TreeNode* root1, TreeNode* root2) {

    vector<int>res;
    getAllElements1dfs(root1,res);
    getAllElements1dfs(root2,res);
    sort(res.begin(), res.end());
    return res;
    }

void getAllElements2dfs(TreeNode *root,vector<int> &nums){
    if (!root) {
        return;
    }
    getAllElements2dfs(root->left, nums);
    nums.push_back(root->val);
    getAllElements2dfs(root->right, nums);
}

vector<int> getAllElements2(TreeNode* root1, TreeNode* root2) {

    vector<int>res1,res2;
    getAllElements2dfs(root1, res1);
    getAllElements2dfs(root2, res2);
    vector<int>res;
    int i=0,j = 0;
    while (i<res1.size() || j<res2.size()){
        //能进入这儿,不代表i不越界...又可能是因为j进来的
        //如果i《j的val....或者j的val已经加完了
        if (i<res1.size() && (j>=res2.size() || res1[i]<res2[j])) {
            res.push_back(res1[i++]);
        }else{
            res.push_back(res2[j++]);
        }
    }
    
    
    return res;
}

void _1305_test()
{
    vector<int> list1 = {2,1,4};
    vector<int> list2 = {1,0,3};
    
    TreeNode *node1 = initTreeWithNULLVector(list1);
    TreeNode *node2 = initTreeWithNULLVector(list2);
     
    vector<int> res1 = getAllElements1(node1,node2);
    vector<int> res2 = getAllElements2(node1,node2);
    
}
