//
//  783_二叉搜索树节点最小距离.cpp
//  testC++++
//
//  Created by yekaihua on 2020/12/26.
//

#import "783_二叉搜索树节点最小距离.hpp"
#import "common.h"

//给定一个二叉搜索树的根节点 root，返回树中任意两节点的差的最小值。
//
//
//
//示例：
//
//输入: root = [4,2,6,1,3,null,null]
//输出: 1
//解释:
//注意，root是树节点对象(TreeNode object)，而不是数组。
//
//给定的树 [4,2,6,1,3,null,null] 可表示为下图:
//
//          4
//        /   \
//      2      6
//     / \
//    1   3
//
//最小的差值是 1, 它是节点1和节点2的差值, 也是节点3和节点2的差值。
//
//
//注意：
//
//二叉树的大小范围在 2 到 100。
//二叉树总是有效的，每个节点的值都是整数，且不重复。
//本题与 530：https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/ 相同
//通过次数23,079提交次数41,288
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

vector<int> inorderVerctorlist(TreeNode *root){
    vector<int>res;
    if (!root) {
        return res;
    }
    auto resleft = inorderVerctorlist(root->left);
    auto resright = inorderVerctorlist(root->right);
    res.insert(res.end(), resleft.begin(),resleft.end());
    res.push_back(root->val);
    res.insert(res.end(), resright.begin(),resright.end());
    return res;
}

//递归
int minDiffInBST1(TreeNode* root) {
    vector<int> res = inorderVerctorlist(root);
    auto size = res.size();
    if (size == 0) {
        return 0;
    }
    int minval = INT_MAX;
    for (int i = 0; i<size; i++) {
        auto val1 = res[i];
        for (int j = i+1; j<size; j++) {
            auto val2 = res[j];
            minval = min(abs(val1-val2), minval);
        }
    }
    return minval;
    }


//迭代---直接中序遍历到左叶子开始计算
int minDiffInBST2(TreeNode* root) {
    int res = 0;
    if (!root) {
        return res;
    }
    res = INT_MAX;
    stack<TreeNode *>mystack;
    TreeNode *last = nullptr;
    while (root || mystack.size()) {
        while (root) {
            mystack.push(root);
            root=root->left;
        }
        root = mystack.top();
        mystack.pop();
        if (last) {
            res = min(res, abs(last->val-root->val));
        }
        last = root;
        root = root->right;
    }
    
    return res;
    }

void _783_test()
{
    vector<int> list1 = {4,2,6,1,3,NULL,NULL};
    
    TreeNode *node1 = initTreeWithNULLVector(list1);
    
    int res1 = minDiffInBST1(node1);
    int res2 = minDiffInBST2(node1);
    
}
