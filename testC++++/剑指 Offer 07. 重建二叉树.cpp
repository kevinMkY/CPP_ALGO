//
//  剑指 Offer 07.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/25.
//

#include "剑指 Offer 07. 重建二叉树.hpp"
#include "common.h"

map<int, int> mymap;
TreeNode* buildTree(vector<int>& preorder,
                    int root,
                    int left,
                    int right) {
    TreeNode* res = nullptr;
    if (left > right) {
        return res;
    }
    int midval = preorder[root];
    int inroot = mymap[midval];
    int size = inroot - left;
    res = new TreeNode(midval);
    res->left = buildTree(preorder, root+1, left, inroot-1);
    res->right = buildTree(preorder, root+size+1, inroot+1, right);
    
    return res;
}


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

    for (int i = 0; i<inorder.size(); i++) {
        mymap[inorder[i]] = i;
    }
    
    TreeNode* res = buildTree(preorder, 0,0, (int)preorder.size()-1);
    return res;
    }

TreeNode *buildTree2Dfs(vector<int>& preorder,int prel,int prer,
                        vector<int>& inorder, int inl,int inr) {
    if (prel > prer || inl > inr) {
        return nullptr;
    }
    
    int preroot = preorder[prel];
    int inrootidx = -1;
    for (int i = inl; i<=inr; i++) {
        if (inorder[i] == preroot) {
            inrootidx = i;
            break;;
        }
    }
    if (inrootidx == -1) {
        return nullptr;
    }
    
    int size = inrootidx - inl;
    TreeNode *root = new TreeNode(preroot);
    root->left = buildTree2Dfs(preorder, prel+1, prel+size, inorder, inl, inrootidx-1);
    root->right = buildTree2Dfs(preorder, prel+size+1, prer, inorder, inrootidx+1, inr);
    
    return root;
}

TreeNode* _offer_07_testbuildTree2(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.size() == 0) {
        return nullptr;
    }
    
    return buildTree2Dfs(preorder,0,preorder.size()-1,
                         inorder,0,inorder.size()-1);
}

void _offer_07_test()
{
    vector<int> list1 = {1,2};
    vector<int> list2 = {2,1};
    
    vector<int> list3 = {3,9,20,15,7};
    vector<int> list4 = {9,3,15,20,7};
    
    
//    TreeNode*res =  buildTree(list1,list2);
    TreeNode*res2 =  _offer_07_testbuildTree2(list3,list4);
    
    
}
