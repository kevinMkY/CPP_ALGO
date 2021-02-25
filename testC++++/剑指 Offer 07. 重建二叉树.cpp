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

void _offer_07_test()
{
    vector<int> list1 = {1,2};
    vector<int> list2 = {2,1};
    
    vector<int> list3 = {3,9,20,15,7};
    vector<int> list4 = {9,3,15,20,7};
    
    
//    TreeNode*res =  buildTree(list1,list2);
    TreeNode*res2 =  buildTree(list3,list4);
    
    
}
