//
//  题库13前序和中序构建二叉树.cpp
//  testC++++
//
//  Created by yekaihua on 2021/3/7.
//

#include "题库13前序和中序构建二叉树.hpp"
#include "common.h"

TreeNode * createBT(vector<int>pre,int root,int l,int r,map<int, int>mymap){
    if(l>r)return nullptr;
    int rootval = pre[root];
    int rootidx = mymap[rootval];
    int leftsize = rootidx-l;
    TreeNode *rootNode = new TreeNode(rootval);
    rootNode->left = createBT(pre,root+1, l,rootidx-1, mymap);
    rootNode->right = createBT(pre,root+1+leftsize, rootidx+1,r, mymap);
    return rootNode;
}

TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
    int n = pre.size();
    if(n==0 || pre.size() != vin.size())return nullptr;
    map<int, int>mymap;
    for(int i=0;i<n;i++){
        mymap[vin[i]]=i;
    }
    return createBT(pre,0, 0, n-1,mymap);
}
void _tk_13_test()
{
    vector<int> pre = {1,2,3,4,5,6,7};
    vector<int> vin = {3,2,4,1,6,5,7};
    TreeNode* res= reConstructBinaryTree(pre,vin);
    
}
