//
//  501_二叉搜索树中的众数.cpp
//  testC++++
//
//  Created by yekaihua on 2020/12/27.
//

#include "501_二叉搜索树中的众数.hpp"
#include "common.h"

//给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。
//
//假定 BST 有如下定义：
//
//结点左子树中所含结点的值小于等于当前结点的值
//结点右子树中所含结点的值大于等于当前结点的值
//左子树和右子树都是二叉搜索树
//例如：
//给定 BST [1,null,2,2],
//
//   1
//    \
//     2
//    /
//   2
//返回[2].
//
//提示：如果众数超过1个，不需考虑输出顺序
//
//进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/find-mode-in-binary-search-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

vector<int> ans;
int base ,basecount,maxcount;

void update(int val){
    if (val == base) {
        basecount++;
    }else{
        base = val;
        basecount=1;
    }
    if (basecount == maxcount) {
        ans.push_back(val);
    }else if (basecount > maxcount){
        ans = {val};
        maxcount = basecount;
    }
}

void dfs(TreeNode *root){
    if (!root) {
        return;
    }
    dfs(root->left);
    update(root->val);
    dfs(root->right);
}

//迭代-dfs
vector<int> findMode1(TreeNode* root) {
    if (!root) {
        return {};
    }
    dfs(root);
    return ans;
    }

vector<int> findMode2(TreeNode* root) {

    vector<int> res;
    if (!root) {
        return res;
    }
    stack<TreeNode *>mystack;
    int base2=0,count2=0,maxcount2=0;
    while (root || mystack.size()) {
        while (root) {
            mystack.push(root);
            root = root->left;
        }
        root = mystack.top();
        if (root->val == base2) {
            count2++;
        }else{
            base2 = root->val;
            count2 = 1;
        }
        if (count2 == maxcount2) {
            res.push_back(root->val);
        }else if (count2 > maxcount2){
            res = {root->val};
            maxcount2 = count2;
        }
        mystack.pop();
        root = root->right;
    }
    return res;
    }

void _501_test()
{
    vector<int> list1 = {1,2,2};
    TreeNode *node1 = initTreeWithNULLVector(list1);
    
    vector<int> res1 = findMode1(node1);
    vector<int> res2 = findMode2(node1);
    
}
