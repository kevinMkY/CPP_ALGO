//
//  429_N 叉树的层序遍历.cpp
//  testC++++
//
//  Created by yekaihua on 2021/1/6.
//

#include "429_N 叉树的层序遍历.hpp"
#include "common.h"
#include "Node.hpp"

//给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。
//
//树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）。
//
//
//
//示例 1：
//
//
//
//输入：root = [1,null,3,2,4,null,5,6]
//输出：[[1],[3,2,4],[5,6]]
//示例 2：
//
//
//
//输入：root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
//输出：[[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
//
//
//提示：
//
//树的高度不会超过 1000
//树的节点总数在 [0, 10^4] 之间
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//迭代
vector<vector<int>> levelOrder1(Node* root) {

    vector<vector<int>> res = {};
    if (!root) {
        return res;
    }
    queue<Node *>myqueue;
    myqueue.push(root);
    int size = 1;
    vector<int> levelres;
    while (myqueue.size()) {
        auto node = myqueue.front();
        myqueue.pop();
        size--;
        levelres.push_back(node->val);
        for (auto childnode : node->children) {
            myqueue.push(childnode);
        }
        if (size == 0) {
            size= myqueue.size();
            res.push_back(levelres);
            levelres = {};
        }
    }
    return res;
    }

void dfslevelOrder2(Node *root,vector<vector<int>> &res,int &depth){
    if (!root) {
        return;
    }
    vector<int> levelres;
    if (res.size() <= depth) {
        levelres = {root->val};
        res.push_back(levelres);
    }else{
        levelres = res[depth];
        levelres.push_back(root->val);
        res[depth] = levelres;
    }
    
    int childdepth = depth+1;
    for (auto childenode : root->children) {
        dfslevelOrder2(childenode, res, childdepth);
    }
}

//递归
vector<vector<int>> levelOrder2(Node* root) {

    vector<vector<int>> res = {};
    if (!root) {
        return res;
    }
    int depth = 0;
    dfslevelOrder2(root,res,depth);
    
    return res;
    }

void _429_test()
{
    vector<int> list1 = {1,NULL,3,2,4,NULL,5,6};
    Node *node1 = initNXTreeWithVector(list1);
    Node *node2 = initNXTreeWithVector(list1);
    
    vector<vector<int>> res1 = levelOrder1(node1);
    vector<vector<int>> res2 = levelOrder2(node2);
    
}
