//
//  257_二叉树的所有路径.cpp
//  testC++++
//
//  Created by yekaihua on 2020/12/21.
//

#include "257_二叉树的所有路径.hpp"
#include "common.h"
//
//给定一个二叉树，返回所有从根节点到叶子节点的路径。
//
//说明: 叶子节点是指没有子节点的节点。
//
//示例:
//
//输入:
//
//   1
// /   \
//2     3
// \
//  5
//
//输出: ["1->2->5", "1->3"]
//
//解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
//通过次数88,605提交次数133,551
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/binary-tree-paths
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

vector<vector<int>> binaryTreePathstest(TreeNode* root) {

    vector<vector<int>> res = {};
    if (!root) {
        return res;
    }
    
    auto val = root->val;
    auto left = root->left;
    auto right = root->right;
    auto resleft = binaryTreePathstest(left);
    auto resright = binaryTreePathstest(right);
    auto sizeleft = resleft.size();
    auto sizeright = resright.size();
    auto maxsize = max(sizeleft, sizeright);
    
    if (maxsize > 0) {
        for (int i = 0; i<sizeleft; i++) {
            vector<int> leftval = resleft[i];
            leftval.insert(leftval.begin(), val);
            res.push_back(leftval);
        }
        for (int i = 0; i<sizeright; i++) {
            vector<int> rightval = resright[i];
            rightval.insert(rightval.begin(), val);
            res.push_back(rightval);
        }
    }else{
        res.push_back({val});
    }
    
    return res;
    }

vector<string> transform(vector<vector<int>>input){
    int size = input.size();
    vector<string> res;
    for (int i = 0; i<size; i++) {
        vector<int> inputval = input[i];
        int inputvalsize = inputval.size();
        string s = "";
        for (int j = 0;j<inputvalsize; j++) {
            if (j>0) {
                s.append("->");
            }
            int lastval = inputval[j];
            string lasts = to_string(lastval);
            s.append(lasts);
        }
        if (inputvalsize > 0) {
            res.push_back(s);
        }
    }
    return res;
}

//递归1
vector<string> binaryTreePaths1(TreeNode* root) {

    vector<vector<int>>res = binaryTreePathstest(root);
    vector<string> finallyres = transform(res);
    return finallyres;
}


//注意paths要传入地址才可以
void digui_257(TreeNode *root,string path,vector<string> &paths){
    if (root) {
        path += to_string(root->val);
        if (!root->left && !root->right) {
            paths.push_back(path);
        }else{
            path+="->";
            digui_257(root->left, path, paths);
            digui_257(root->right, path, paths);
        }
    }
}

//递归2--深度优先
vector<string> binaryTreePaths2(TreeNode* root) {

    vector<string> res;
    if (!root) {
        return res;
    }
    digui_257(root,"",res);
    
    return res;
    }

//迭代--广度优先---这个方法不正确,输出顺序有问题
vector<string> binaryTreePaths3(TreeNode* root) {

    vector<string> res;
    if (!root) {
        return res;
    }
    queue<TreeNode *>myqueue;
    queue<string> stringqueue;
    myqueue.push(root);
    stringqueue.push(to_string(root->val));
    while (!myqueue.empty()) {
        auto node = myqueue.front();
        myqueue.pop();
        auto sval = stringqueue.front();
        auto temps = sval;
        stringqueue.pop();
        auto left = node->left;
        auto right = node->right;
        if (left) {
            myqueue.push(left);
            temps+="->";
            temps+=to_string(left->val);
            stringqueue.push(temps);
        }
        temps = sval;
        if (right) {
            myqueue.push(right);
            temps+="->";
            temps+=to_string(right->val);
            stringqueue.push(temps);
        }
        if (!left && !right) {
            res.push_back(sval);
        }
        
    }
    return res;
    }


void _257_test()
{
    vector<int> list1 = {1,2,3,4,5,NULL,6};
        
    TreeNode *node1 = initTreeWithNULLVector(list1);
    
    vector<string> res1 = binaryTreePaths1(node1);
    vector<string> res2 = binaryTreePaths2(node1);
    vector<string> res3 = binaryTreePaths3(node1);
    
    
}
