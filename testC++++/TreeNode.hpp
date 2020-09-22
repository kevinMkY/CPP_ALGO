//
//  TreeNode.hpp
//  testC++++
//
//  Created by ykh on 2020/9/22.
//

#ifndef TreeNode_h
#define TreeNode_h

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


static TreeNode *AddNodeToTree(TreeNode *root,int val){
    if (root == nullptr) {
        TreeNode *node = new TreeNode(val);
        return node;
    }

    if (root->val > val) {
        TreeNode *nextleft = AddNodeToTree(root->left, val);
        root->left = nextleft;
    }else if (root->val < val) {
        TreeNode *nextRight = AddNodeToTree(root->right, val);
        root->right = nextRight;
    }else{      //  ==
        
    }
    return root;
}

static TreeNode *initTreeWithVector (std::vector<int> para){

    int size = para.size();
    TreeNode *res = nullptr;
    if (size == 0) {
        return res;
    }
    
    for (int i = 0; i<size; i++) {
        int val = para[i];
        res = AddNodeToTree(res,val);
    }
    
    return res;
}

#endif /* TreeNode_h */
