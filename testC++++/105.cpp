//
//  105.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/25.
//

#include "105.hpp"
#include "common.h"

map<int , int>_105_repeat_testbuildTreemymap;

TreeNode* _105_repeat_testbuildTree(vector<int>& preorder,
                                    int root,
                                    int left,
                                    int right) {
    TreeNode* res = nullptr;
    if (left > right) {
        return res;
    }
    int midval = preorder[root];
    int inroot = _105_repeat_testbuildTreemymap[midval];
    int size = inroot - left;
    res = new  TreeNode(midval);
    res->left = _105_repeat_testbuildTree(preorder, root+1, left, inroot-1);
    res->right = _105_repeat_testbuildTree(preorder, root + size + 1,inroot+1,right);
    return res;
}


TreeNode* _105_repeat_testbuildTree(vector<int>& preorder, vector<int>& inorder) {

    
    for (int i = 0; i<inorder.size(); i++) {
        _105_repeat_testbuildTreemymap[inorder[i]] = i;
    }
    TreeNode* res = _105_repeat_testbuildTree(preorder,0,0,inorder.size()-1);
    return res;
    }

void _105_repeat_test()
{
    vector<int> list1 = {3,9,20,15,7};
    vector<int> list2 = {9,3,15,20,7};
    
    TreeNode*res = _105_repeat_testbuildTree(list1,list2);
    
}
